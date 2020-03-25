#include "Washer.h"

Washer::Washer() : Appliance(), machineState(NO_OPERATION) {};
Washer::Washer(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption), machineState(NO_OPERATION) {};
int Washer::getMachineState() const {
	return machineState;
}
void Washer::setMachineState(int machineState) {
	this->machineState = machineState;
}
void Washer::stateView() {
	cout << "제품명 : " << getMachineName();
	if (getPowerFlag() == false) {
		cout << " (OFF) " << endl;
		return;
	}
	else
		cout << " (ON) ";
	switch (machineState) {
	case NO_OPERATION: cout << " 설정상태 : 무동작" << endl; break;
	case GENERAL: cout << " 설정상태 : 일반빨래" << endl; break;
	case BOIL: cout << " 설정상태 : 삶은빨래" << endl; break;
	case DRY: cout << " 설정상태 : 건조" << endl; break;
	}
}