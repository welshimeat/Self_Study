#include "Appliance.h"

Appliance::Appliance() : machineName(""), powerFlag(false) {}
Appliance::Appliance(string machineName, bool powerFlag) : machineName(machineName), powerFlag(powerFlag) {}
string Appliance::getMachineName() const {
	return machineName;
}
bool Appliance::getPowerFlag() const {
	return powerFlag;
}
void Appliance::setMachineName(string machineName) {
	this->machineName = machineName;
}
void Appliance::setPowerFlag(bool powerFlag) {
	this->powerFlag = powerFlag;
}
bool Appliance::turnOn() {
	if (powerFlag == true)
		return false;
	else return true;
}
bool Appliance::turnOff() {
	if (powerFlag == false)
		return false;
	else return true;
}
void Appliance::stateView() {
	cout << "Α¦Η°Έν : " << machineName;
	cout << "(";
	if (powerFlag == true)
		cout << "ON";
	else
		cout << "OFF";
	cout << ")";
}
