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
	cout << "��ǰ�� : " << getMachineName();
	if (getPowerFlag() == false) {
		cout << " (OFF) " << endl;
		return;
	}
	else
		cout << " (ON) ";
	switch (machineState) {
	case SENDAIR: cout << " �������� : ��ǳ"; break;
	case COOLER: cout << " �������� : �ù�"; break;
	case HEATER: cout << " �������� : ����"; break;
	}
	cout << "(�����µ� : " << setTemperature << ")" << endl;
}
