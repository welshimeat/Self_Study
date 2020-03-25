#include "Power.h"
#include "HomeAutomation.h"

int Power::calPowerConsumption(HomeAutomation& rHa) {
	int sum = 0;
	for (int i = 0; i < rHa.applianceCnt; i++) {
		if (rHa.applianceArray[i]->getPowerFlag() == true)
			rHa.applianceArray[i]->turnOff();
		sum += (((rHa.applianceArray[i])->getPowerConsumption()) * (((rHa.applianceArray[i])->getUseHour())/60));
	}
	return sum;
}