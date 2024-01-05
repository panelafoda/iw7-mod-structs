//this were made with the pmove_t address 145227510

class pmove_t
{
public:
	char pad_0000[8]; //0x0000
	class playerState_s* ps; //0x0008
	int32_t buttons; //0x0010
}; //Size: 0x0014

class PlayerActiveWeaponState
{
public:
	int32_t weapAnim; //0x0000
	int32_t weaponTime; //0x0004
	int32_t weaponDelay; //0x0008
	int32_t weaponRestrictKickTime; //0x000C
	int32_t weaponState; //0x0010
	char pad_0014[32]; //0x0014
}; //Size: 0x0034

class PlayerEquippedWeaponState
{
public:
	bool usedBefore; //0x0000
	bool dualWielding; //0x0001
	bool inAltMode; //0x0002
	bool needsRechamber[2]; //0x0003
	char pad_0005[19]; //0x0005
}; //Size: 0x0018

class StockAmmo
{
public:
	int32_t Ammo; //0x0000
	char pad_0004[20]; //0x0004
}; //Size: 0x0018

class ClipAmmo
{
public:
	int32_t Ammo[2]; //0x0000
	char pad_0008[28]; //0x0008
}; //Size: 0x0024

class playerState_s
{
public:
	int32_t commandtime; //0x0000
	char pad_0004[8]; //0x0004
	int32_t pm_flags; //0x000C
	char pad_0010[24]; //0x0010
	float origin[3]; //0x0028
	float velocity[3]; //0x0034
	char pad_0040[728]; //0x0040
	int32_t lastSprintStart; //0x0318
	int32_t lastSprintEnd; //0x031C
	char pad_0320[820]; //0x0320
	class PlayerActiveWeaponState weapState[2]; //0x0654
	int32_t weaponsEquipped[15]; //0x06BC
	class PlayerEquippedWeaponState weapEquippedData[15]; //0x06F8
	char pad_0860[32]; //0x0860
	int32_t weapon; //0x0880
	char pad_0884[16]; //0x0884
	float fWeaponPosFrac; //0x0894
	char pad_0898[36]; //0x0898
	bool DualWielding; //0x08BC
	char pad_08BD[23]; //0x08BD
	class StockAmmo StockAmmoArray[15]; //0x08D4
	class ClipAmmo ClipAmmoArray[15]; //0x0A3C
}; //Size: 0x0C58