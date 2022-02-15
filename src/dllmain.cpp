#include "pch.h"
#include "structOffsets.h"
#include "base.h"

//Global variables
bool quit = false;

bool playerGodMode = false;
bool unlimitedMoney = false;
bool unlimitedAmmo = false;
bool playerSpeed = false;
bool noWeaponDelay = false;
bool noUtilityDelay = false;
bool playerTriggerbot = false;
bool playerAimbot = false;
float playerFovValue = 65;
DWORD updateLoop = 10;

Player* localPlayer = nullptr;
Health* localHealth = nullptr;
Speed* localPlayerSpeed = nullptr;
ZombieEntityList1* localZombieEntityList = nullptr;
MoneyAndName* localMoneyAndName = nullptr;
Cfg* localCfg = nullptr;

int restoreMoney;
int restoreHealth;
int restoreWeapon1Mag, restoreWeapon2Mag, restoreWeapon3Mag, restoreGrenades;
int restorePlayerSpeed;

//Get module base address
uintptr_t moduleBase = (uintptr_t)GetModuleHandle("BGamerT5.exe");

char boolToChar(bool boolean) //Converts a bool to represent a char when we want to write it out
{
	if (boolean == true)
	{
		return (char)'X';
	}
	else
	{
		return 0;
	}
}

void TextDraw() //The console gui
{
	system("cls"); //Clears console
	std::cout << "Successfully Injected, Version 1.1, press delete key to exit \n" << std::endl;
	std::cout << "GodMode                 [" << boolToChar(playerGodMode) << "] - Press f1 to toggle" << std::endl;
	std::cout << "Unlimited Money         [" << boolToChar(unlimitedMoney) << "] - Press f2 to toggle" << std::endl;
	std::cout << "Unlimited Ammo          [" << boolToChar(unlimitedAmmo) << "] - Press f3 to toggle" << std::endl;
	std::cout << "Sonic Speed             [" << boolToChar(playerSpeed) << "] - Press f4 to toggle" << std::endl;
	std::cout << "No Weaponfire Delay     [" << boolToChar(noWeaponDelay) << "] - Press f5 to toggle" << std::endl;
	std::cout << "No Grenade & knife Delay[" << boolToChar(noUtilityDelay) << "] - Press f6 to toggle" << std::endl;
	std::cout << "Triggerbot              [" << boolToChar(playerTriggerbot) << "] - Press f7 to toggle" << std::endl;
	std::cout << "Aimbot (on weapon ads)  [" << boolToChar(playerAimbot) << "] - Press f8 to toggle" << std::endl;
	std::cout << "Fov Changer             [" << playerFovValue << "] - Press f9 to increase and f10 to decrease" << std::endl;
	std::cout << "Hack Update Speed       [" << updateLoop << "ms] - Press f11 to increase and f12 to decrease" << std::endl;
}

void GetInput() //Gets input and restores values
{
	if (GetAsyncKeyState(VK_F1) & 1)
	{
		if (playerGodMode == true)
		{
			playerGodMode = false;
			localHealth->PlayerHealth = restoreHealth;
		}
		else
		{
			playerGodMode = true;
			restoreHealth = localHealth->PlayerHealth;
			localHealth->PlayerHealth = restoreHealth;
		}
		TextDraw();
	}
	else if (GetAsyncKeyState(VK_F2) & 1)
	{
		if (unlimitedMoney == true)
		{
			unlimitedMoney = false;
			localMoneyAndName->Money = restoreMoney; //Restore money when unlimitedMoney is disabled
		}
		else
		{
			unlimitedMoney = true;
			restoreMoney = localMoneyAndName->Money; //Set restoreMoney value
			localMoneyAndName->Money = 99999; //Set localMoneyAndName->Money to 99999 once before localMoneyAndName->Money begins otherwise added money from killing zombies wont be correct
		}
		TextDraw();
	}
	else if (GetAsyncKeyState(VK_F3) & 1)
	{
		if (unlimitedAmmo == true)
		{
			unlimitedAmmo = false;
			localPlayer->Weapon1Mag = restoreWeapon1Mag;
			localPlayer->Weapon2Mag = restoreWeapon2Mag;
			localPlayer->Weapon3Mag = restoreWeapon3Mag;
			localPlayer->Grenades = restoreGrenades;
		}
		else
		{
			unlimitedAmmo = true;
			restoreWeapon1Mag = localPlayer->Weapon1Mag;
			restoreWeapon1Mag = localPlayer->Weapon2Mag;
			restoreWeapon1Mag = localPlayer->Weapon3Mag;
			restoreWeapon1Mag = localPlayer->Grenades;
			localPlayer->Weapon1Mag = restoreWeapon1Mag;
			localPlayer->Weapon1Mag = restoreWeapon2Mag;
			localPlayer->Weapon1Mag = restoreWeapon3Mag;
			localPlayer->Weapon1Mag = restoreGrenades;
		}
		TextDraw();
	}
	else if (GetAsyncKeyState(VK_F4) & 1)
	{
		if (playerSpeed == true)
		{
			playerSpeed = false;
			localPlayerSpeed->PlayerSpeed = restorePlayerSpeed;
		}
		else
		{
			playerSpeed = true;
			restorePlayerSpeed = localPlayerSpeed->PlayerSpeed;
			localPlayerSpeed->PlayerSpeed = restorePlayerSpeed;
		}
		TextDraw();
	}
	else if (GetAsyncKeyState(VK_F5) & 1)
	{
		if (noWeaponDelay == true)
		{
			noWeaponDelay = false;
			mem::nop::restoreNopFunc((PVOID)0x007669EC, 2, "\x89\x10"); //Gun
		}
		else
		{
			noWeaponDelay = true;
			mem::nop::nopFunc((PVOID)0x007669EC, 2);
		}
		TextDraw();
	}
	else if (GetAsyncKeyState(VK_F6) & 1)
	{
		if (noUtilityDelay == true)
		{
			noUtilityDelay = false;
			mem::nop::restoreNopFunc((PVOID)0x007670B8, 3, "\x89\x56\x3C"); //Knife
			mem::nop::restoreNopFunc((PVOID)0x007696E4, 3, "\x83\x38\x00"); //Grenade
		}
		else
		{
			noUtilityDelay = true;
			mem::nop::nopFunc((PVOID)0x007670B8, 3); //Knife
			mem::nop::nopFunc((PVOID)0x007696E4, 3); //Grenade
		}
		TextDraw();
	}
	else if (GetAsyncKeyState(VK_F7) & 1)
	{
		if (playerTriggerbot == true)
		{
			playerTriggerbot = false;
		}
		else
		{
			playerTriggerbot = true;
		}
		TextDraw();
	}
	else if (GetAsyncKeyState(VK_F8) & 1)
	{
		if (playerAimbot == true)
		{
			playerAimbot = false;
		}
		else
		{
			playerAimbot = true;
		}
		TextDraw();
	}
	else if (GetAsyncKeyState(VK_F9) & 1)
	{
		playerFovValue += 5;
		TextDraw();
	}
	else if (GetAsyncKeyState(VK_F10) & 1)
	{
		if (playerFovValue > 5)
		{
			playerFovValue -= 5;
			TextDraw();
		}
	}
	else if (GetAsyncKeyState(VK_F11) & 1)
	{
		updateLoop += 5;
		TextDraw();
	}
	else if (GetAsyncKeyState(VK_F12) & 1)
	{
		if (updateLoop > 11)
		{
			updateLoop -= 5;
			TextDraw();
		}
		else if (updateLoop > 2)
		{
			updateLoop -= 1;
			TextDraw();
		}
	}
	else if (GetAsyncKeyState(VK_DELETE) & 1)
	{
		quit = true;
	}
}

void Hacks()
{
	//if (localHealth) checks if the adress exists so when you are in for example main menu and it doesnt exit it wont just write to some random adress, same for all the other ifs
	if (localHealth)
	{
		if (playerGodMode == true)
		{
			localHealth->PlayerHealth = 10000;
		}
	}
	if (localMoneyAndName)
	{
		if (unlimitedMoney == true)
		{
			restoreMoney = (restoreMoney + (localMoneyAndName->Money)) - 99999; //Get added money from killing zombies and store them
			localMoneyAndName->Money = 99999; //Constantly set money to 99999
		}
	}
	if (localPlayer)
	{
		if (unlimitedAmmo == true)
		{
			localPlayer->Weapon1Mag = 300;
			localPlayer->Weapon2Mag = 300;
			localPlayer->Weapon3Mag = 300;
			localPlayer->Grenades = 300;
		}
	}
	if (localPlayerSpeed)
	{
		if (playerSpeed == true)
		{
			localPlayerSpeed->PlayerSpeed = 400;
		}
	}
	//Always on except when its the same value because thats just a waste of pc resources
	if (!localCfg->PlayerFov == localCfg->PlayerFov)
	{
		localCfg->PlayerFov = playerFovValue;
	}
}

DWORD WINAPI HookThread(HMODULE hModule)
{
	AllocConsole();                        //Allocate and create console
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);
	HWND hwndConsole = GetConsoleWindow(); //Get window of console
	HMENU hmenuConsole = GetSystemMenu(hwndConsole, FALSE);
	SetConsoleTitleA("BO1Z Gamer Hack"); //Sets console title
	EnableMenuItem(hmenuConsole, SC_CLOSE, MF_GRAYED); //Sets the x icon in the corner to be gray
	TextDraw(); //To write first time

	//Initialize addresses
	localPlayer = *(Player**)(moduleBase + 0x1653770);
	localHealth = *(Health**)(moduleBase + 0x12E9A0);
	localPlayerSpeed = *(Speed**)(moduleBase + 0x1801810);
	localZombieEntityList = *(ZombieEntityList1**)(moduleBase + 0x017FBD9C);
	localMoneyAndName = *(MoneyAndName**)(moduleBase + 0x024C4FE0);
	localCfg = *(Cfg**)(moduleBase + 0x2BF6888);

	while (quit == false) //Program loop
	{
		GetInput();
		Hacks();
		Sleep(updateLoop);
	}

	//cleanup
	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

int APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)HookThread, hModule, NULL, nullptr);
	case DLL_PROCESS_DETACH:
		break; //eject
	}
	return TRUE;
}