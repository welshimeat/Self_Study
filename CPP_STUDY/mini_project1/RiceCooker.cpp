#pragma once
#include "RiceCooker.h"

RiceCooker::RiceCooker() : Appliance(), machineState(NO_OPERATION) {}
RiceCooker::RiceCooker(string machineName) : Appliance(machineName), machineState(NO_OPERATION) {}
int RiceCooker::getMachineState() const{ return machineState;}
void RiceCooker::setMachineState(int machineState){
  this->machineState = machineState;
}
void RiceCooker::stateView(){
  this->Appliance::stateView();
  switch(machineState){
  case NO_OPERATION: cout << endl; break;
    case WARM : cout << " �������� : ����" << endl; break;
    case COOK : cout << " �������� : ������" << endl; break;
    case HEAT : cout << " �������� : �����" << endl; break;
  }
}
