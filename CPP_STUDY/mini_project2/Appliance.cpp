#include "Appliance.h"

Appliance::Appliance() : machineName(""), powerFlag(false), powerConsumption(0), startHour(0), useHour(0) {}
Appliance::Appliance(string machineName, int powerConsumption, bool powerFlag, time_t startHour, time_t useHour) : machineName(machineName), powerConsumption(powerConsumption), powerFlag(powerFlag), startHour(startHour), useHour(useHour) {}
string Appliance::getMachineName() const {
	return machineName;
}
bool Appliance::getPowerFlag() const {
	return powerFlag;
}
int Appliance::getPowerConsumption() const {
	return powerConsumption;
}
time_t Appliance::getStartHour() {
	return startHour;
}
time_t Appliance::getUseHour() {
	return useHour;
}
void Appliance::setMachineName(string machineName) {
	this->machineName = machineName;
}
void Appliance::setPowerFlag(bool powerFlag) {
	this->powerFlag = powerFlag;
}
void Appliance::setPowerConsumption(int powerConsumption) {
	this->powerConsumption = powerConsumption;
}
bool Appliance::turnOn() {
	if (powerFlag == true)
		return false;
	else {
		powerFlag = true;
		time(&startHour);
		return true;
	}
}
bool Appliance::turnOff() {
	time_t currentTime;
	if (powerFlag == false)
		return false;
	else {
		powerFlag = false;
		time(&currentTime);
		useHour += (currentTime - startHour);
		return true;
	}
}