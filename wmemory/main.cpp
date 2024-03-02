#include "include.h"

#include "wmemory.hpp"
#include "offsets.h"

int main()
{
	while (true)
	{
		uint64 localPlayerPawn = wmemory.ReadMemory<uint64>(Offsets::client + Offsets::dwLocalPlayerPawn);
		if (localPlayerPawn == NULL)
			continue;

		uint64 cameraServices = wmemory.ReadMemory<uint64>(localPlayerPawn + Offsets::m_pCameraServices);
		if (cameraServices == NULL)
			continue;

		wmemory.WriteMemory<sint32>(cameraServices + Offsets::m_iFOV, 144);
	}

	return 0;
}