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
    case WARM : cout << " 설정상태 : 보온" << endl; break;
    case COOK : cout << " 설정상태 : 밥짓기" << endl; break;
    case HEAT : cout << " 설정상태 : 데우기" << endl; break;
  }
}
