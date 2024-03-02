#ifndef OFFSETS_H
#define OFFSETS_H

Wmemory wmemory(L"cs2.exe");

namespace Offsets
{
	adr64 client = wmemory.GetModuleBase(L"client.dll");

	adr64 dwLocalPlayerPawn = 0x1730118;

	adr32 m_pCameraServices = 0x1138;
	adr32 m_iFOV = 0x210;
}

#endif