#include "pch.h"
#include "base.h"

void mem::nop::nopFunc(PVOID memAdress, int sizeOfNop) //Our nop function takes an adress and nops 'sizeOfNop' amount of bytes
{
    DWORD newProtect, oldProtect;
    VirtualProtect(memAdress, sizeOfNop, PAGE_EXECUTE_READWRITE, &oldProtect); //Changes write permissions
    memset(memAdress, NOP, sizeOfNop); //Sets sizeOfNop to nop
    VirtualProtect(memAdress, sizeOfNop, oldProtect, &newProtect); //Restores permissions (not needed but good practice)
}

void mem::nop::restoreNopFunc(PVOID memAdress, int sizeOfNop, const char* restoreOpCode) //Our restoreNop function does the opposite and copies 'sizeOfNop' amount of bytes to the memory adress
{
    DWORD newProtect, oldProtect;
    VirtualProtect(memAdress, sizeOfNop, PAGE_EXECUTE_READWRITE, &oldProtect); //Changes write permissions
    memcpy(memAdress, (BYTE*)restoreOpCode, sizeOfNop); //restores the memAdress's nops
    VirtualProtect(memAdress, sizeOfNop, oldProtect, &newProtect); //Restores permissions (not needed but good practice)
}