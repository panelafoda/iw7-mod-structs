#include <std_include.hpp>
#include "loader/component_loader.hpp"
#include "component/console/console.hpp"
#include "game/game.hpp"
#include "game/dvars.hpp"



#include <utils/hook.hpp>
#include <utils/string.hpp>
#include <utils/memory.hpp>
#include <utils/io.hpp>

namespace mirele
{
	bool IsSprinting(const playerState_s* ps)
	{
		return ps->lastSprintStart > ps->lastSprintEnd;
	}

	game::dvar_t* SprintSwaps = nullptr;
	utils::hook::detour PM_Weapon_hook;
	void PM_Weapon_stub(mirele::pmove_t* pm, void* pml)
	{
		//removes the delay before shooting after a yy
		for (int index = 0; index < 2; index++)
		{
			if (pm->ps->weapState[index].weaponTime > 0 && pm->ps->weapState[index].weaponState == 0 && (pm->ps->weapState[index].weapAnim == 1 || pm->ps->weapState[index].weapAnim == 129))
			{
				pm->ps->weapState[index].weaponTime = 0;
			}
		}

		int RightHandAnim = pm->ps->weapState[0].weapAnim;
		int LeftHandAnim = pm->ps->weapState[1].weapAnim;
		PM_Weapon_hook.invoke(pm, pml);
		if (SprintSwaps->current.enabled)
		{
			if ((pm->ps->weapState[0x0].weaponState == 5 || pm->ps->weapState[0x0].weaponState == 6) && IsSprinting(pm->ps))
			{
				pm->ps->weapState[0].weapAnim = RightHandAnim;
				pm->ps->weapState[1].weapAnim = LeftHandAnim;
			}
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			SprintSwaps = game::Dvar_RegisterBool("SprintSwaps", true, game::DVAR_FLAG_SAVED, "");
			PM_Weapon_hook.create(0x71E5E0_b, PM_Weapon_stub);
		}
	};
}

REGISTER_COMPONENT(mirele::component)