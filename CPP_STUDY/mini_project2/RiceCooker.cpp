#pragma once
#include "RiceCooker.h"

RiceCooker::RiceCooker() : Appliance(), machineState(NO_OPERATION) {}
RiceCooker::RiceCooker(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption), machineState(NO_OPERATION) {}
int RiceCooker::getMachineState() const { return machineState; }
void RiceCooker::setMachineState(int machineState) {
	this->machineState = machineState;
}
void RiceCooker::stateView() {
	cout << "��ǰ�� : " << getMachineName();
	if (getPowerFlag() == false) {
		cout << " (OFF) " << endl;
		return;
	}
	else
		cout << " (ON) ";
	switch (machineState) {
	case NO_OPERATION: cout << " �������� : ������" << endl; break;
	case WARM: cout << " �������� : ����" << endl; break;
	case COOK: cout << " �������� : ������" << endl; break;
	case HEAT: cout << " �������� : �����" << endl; break;
	}
}
