#pragma once
//This header contains all the offsets, classes and structs we will need for the hack.
#include "base.h"

class Adresses //All addresses here don't have classes (from cheat table)
{
public:
//	DWORD Health = moduleBase + 0x12E9A0;
//	DWORD Player = moduleBase + 0x1653770;
//	DWORD PlayerSpeed = moduleBase + 0x1801810;
//	DWORD ZombieEntityList = moduleBase + 0x017FBD9C;
//	DWORD MoneyAndName = moduleBase + 0x024C4FE0;
//	DWORD Cfg = moduleBase + 0x2BF6888;

};

// Created with ReClass.NET 1.2 by KN4CK3R (from ReClass file)

class Player
{
public:
	char pad_0000[8]; //0x0000
	float Movement_Q; //0x0008
	char pad_000C[24]; //0x000C
	float PosX; //0x0024
	float PosY; //0x0028
	float PosZ; //0x002C
	float VelocityX; //0x0030
	float VelocityY; //0x0034
	float VelocityZ; //0x0038
	int32_t CurrentWeaponDelay; //0x003C
	char pad_0040[320]; //0x0040
	float Yaw; //0x0180
	float Pitch; //0x0184
	char pad_0188[60]; //0x0188
	int32_t Health; //0x01C4
	char pad_01C8[384]; //0x01C8
	int32_t Weapon1Reserve; //0x0348
	char pad_034C[12]; //0x034C
	int32_t Weapon2Reserve; //0x0358
	char pad_035C[12]; //0x035C
	int32_t Weapon3Reserve; //0x0368
	char pad_036C[84]; //0x036C
	int32_t Weapon1Mag; //0x03C0
	char pad_03C4[4]; //0x03C4
	int32_t Grenades; //0x03C8
	char pad_03CC[4]; //0x03CC
	int32_t Weapon2Mag; //0x03D0
	char pad_03D4[12]; //0x03D4
	int32_t Weapon3Mag; //0x03E0
	char pad_03E4[5612]; //0x03E4
}; //Size: 0x19D0

class ZombieEntityList3
{
public:
	class Zombie1_3* ZomibePtr1; //0x0000
	char pad_0004[136]; //0x0004
	class Zombie2_3* ZombiePtr2; //0x008C
	char pad_0090[136]; //0x0090
	class Zombie3_3* ZombiePtr3; //0x0118
	char pad_011C[1828]; //0x011C
}; //Size: 0x0840

class Zombie1_3
{
public:
	char pad_0000[24]; //0x0000
	float PosX; //0x0018
	float PosY; //0x001C
	float PosZ; //0x0020
	char pad_0024[352]; //0x0024
	int32_t CurrentHealth; //0x0184
	int32_t OriginalHealth; //0x0188
	char pad_018C[120]; //0x018C
}; //Size: 0x0204

class Zombie2_3
{
public:
	char pad_0000[1028]; //0x0000
}; //Size: 0x0404

class Zombie3_3
{
public:
	char pad_0000[1028]; //0x0000
}; //Size: 0x0404

class Health
{
public:
	char pad_0000[388]; //0x0000
	int32_t PlayerHealth; //0x0184
	int32_t OriginalHealth_Q; //0x0188
	char pad_018C[4788]; //0x018C
}; //Size: 0x1440

class MoneyAndName
{
public:
	char pad_0000[80]; //0x0000
	char Name[4]; //0x0050
	char pad_0054[76]; //0x0054
	int32_t Money; //0x00A0
	char pad_00A4[3996]; //0x00A4
}; //Size: 0x1040

class ZombieEntityList2
{
public:
	class Zombie1_2* ZombiePtr1; //0x0000
	char pad_0004[136]; //0x0004
	class Zombie2_2* Zombie2Ptr; //0x008C
	char pad_0090[304]; //0x0090
}; //Size: 0x01C0

class Zombie1_2
{
public:
	char pad_0000[388]; //0x0000
	int32_t Health; //0x0184
	int32_t OrignialHealth; //0x0188
	char pad_018C[628]; //0x018C
}; //Size: 0x0400

class Speed
{
public:
	char pad_0000[24]; //0x0000
	int32_t PlayerSpeed; //0x0018
	char pad_001C[8232]; //0x001C
}; //Size: 0x2044

class ZombieEntityList1
{
public:
	class Zombie1_1* Zombie1Ptr; //0x0000
	char pad_0004[136]; //0x0004
	class Zombie2_1* Zombie2Ptr; //0x008C
	char pad_0090[176]; //0x0090
}; //Size: 0x0140

class Zombie2_2
{
public:
	char pad_0000[1028]; //0x0000
}; //Size: 0x0404

class Zombie1_1
{
public:
	char pad_0000[388]; //0x0000
	int32_t Health; //0x0184
	int32_t OriginalHealth; //0x0188
	char pad_018C[632]; //0x018C
}; //Size: 0x0404

class Zombie2_1
{
public:
	char pad_0000[388]; //0x0000
	int32_t Health; //0x0184
	int32_t OriginalHealth; //0x0188
	char pad_018C[888]; //0x018C
}; //Size: 0x0504

class Cfg
{
public:
	char pad_0000[24]; //0x0000
	float PlayerFov; //0x0018
	char pad_001C[12]; //0x001C
	float PlayerOriginalFov; //0x0028
	char pad_002C[4628]; //0x002C
}; //Size: 0x1240