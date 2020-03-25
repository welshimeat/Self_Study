#include "AirConditioner.h"

AirConditioner::AirConditioner() : Appliance(), machineState(SENDAIR), setTemperature(25) {};
AirConditioner::AirConditioner(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption), machineState(SENDAIR), setTemperature(25) {}
int AirConditioner::getMachineState() const {
	return machineState;
}
int AirConditioner::getSetTemperature() const {
	return setTemperature;
}
void AirConditioner::setMachineState(int machineStete) {
	this->machineState = machineState;
}
void AirConditioner::setSetTemperature(int setTemperature) {
	this->setTemperature = setTemperature;
}
AirConditioner& AirConditioner::operator++() {
	setTemperature++;
	return *this;
}
AirConditioner& AirConditioner::operator--() {
	setTemperature--;
	return *this;
}
void AirConditioner::stateView() {
	cout << "제품명 : " << getMachineName();
	if (getPowerFlag() == false) {
		cout << " (OFF) " << endl;
		return;
	}
	else
		cout << " (ON) ";
	switch (machineState) {
	case SENDAIR: cout << " 설정상태 : 송풍"; break;
	case COOLER: cout << " 설정상태 : 냉방"; break;
	case HEATER: cout << " 설정상태 : 난방"; break;
	}
	cout << "(설정온도 : " << setTemperature << ")" << endl;
}
