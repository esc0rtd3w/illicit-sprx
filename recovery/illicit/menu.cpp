
/*
#include "menu.h"


void updateVehicleManager()
{
	// Vehicles -> Manager
	Menu_f::addMenu("Vehicle Manager", Menu_f::MenuVehiclesManager, Menu_f::MenuVehicles);

	for (int slot = 0; slot < numberOfSpawnedVehicles; slot++)
	{
		char vehicleIDc[64];
		sprintf(vehicleIDc, "%i", spawnedVehicleList[slot]);

		Menu_f::addHookedOption(vehicleIDc, &Vehicles_f::DeleteVehicleFromManager, spawnedVehicleList[slot]);

		
		if (spawnedVehicleList[slot] == 0)
		{
			addOption("**No Vehicle In Slot**");
		}
		else
		{
			addHookedOption(vehicleIDc, &Vehicles_f::DeleteVehicleFromManager, spawnedVehicleList[slot]);
		}
		
	}
}
*/