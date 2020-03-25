#include "HomeAutomation.h"

HomeAutomation::HomeAutomation() {
	for (int i = 0; i < Appliance_MAX_CNT; i++) {
		riceCookerArray[i] = NULL;
	}
	riceCookerCnt = 0;
}

HomeAutomation::HomeAutomation(const HomeAutomation& r) {
	riceCookerCnt = r.riceCookerCnt;
	for (int i = 0; i < riceCookerCnt; i++) {
		riceCookerArray[i] = new RiceCooker;
		*riceCookerArray[i] = *r.riceCookerArray[i];
	}
}

HomeAutomation::~HomeAutomation() {
	for (int i = 0; i < riceCookerCnt; i++) {
		delete riceCookerArray[i];
	}
}

RiceCooker** HomeAutomation::getRiceCookerArray() {
	return riceCookerArray;
}

int HomeAutomation::getRiceCookerCnt() const {
	return riceCookerCnt;
}

HomeAutomation& HomeAutomation::operator=(const HomeAutomation& r) {
	for (int i = 0; i < riceCookerCnt; i++) {
		delete riceCookerArray[i];
	}
	riceCookerCnt = r.riceCookerCnt;
	for (int i = 0; i < riceCookerCnt; i++) {
		riceCookerArray[i] = new RiceCooker;
		*riceCookerArray[i] = *r.riceCookerArray[i];
	}
	return *this;
}

bool HomeAutomation::addAppliance(RiceCooker* ap) {
	if (riceCookerCnt >= Appliance_MAX_CNT)
		return false;
	for (int i = 0; i < riceCookerCnt; i++) {
		if (riceCookerArray[i]->getMachineName() == ap->getMachineName()) {
			cout << "������ �̸��� ��� ��� �Ұ�\n";
			return false;
		}
	}
	riceCookerArray[riceCookerCnt] = new RiceCooker;
	*riceCookerArray[riceCookerCnt++] = *ap;
	return true;
}

int HomeAutomation::searchMachine(string machineName) {
	for (int i = 0; i < riceCookerCnt; i++) {
		if (riceCookerArray[i]->getMachineName() == machineName) {
			return i;
		}
	}
	return -1;
}

bool HomeAutomation::deleteAppliance(string machineName) {
	for (int i = 0; i < riceCookerCnt; i++) {
		if (riceCookerArray[i]->getMachineName() == machineName) {
			delete riceCookerArray[i];
			for (int j = i; j < riceCookerCnt - 1; j++) {
				riceCookerArray[j] = riceCookerArray[j + 1];
			}
			riceCookerCnt--;
			return true;
		}
	}
	return false;
}

void HomeAutomation::listDisplayAppliance() {
	for (int i = 0; i < riceCookerCnt; i++) {
		riceCookerArray[i]->stateView();
	}
}

bool HomeAutomation::controlAppliance(string machineName) {
	for (int i = 0; i < riceCookerCnt; i++) {
		if (riceCookerArray[i]->getMachineName() == machineName) {
			setStateAppliance(riceCookerArray[i]);
			return true;
		}
	}
	cout << "** �ش��ϴ� ��ǰ�� �������� �ʽ��ϴ�.\n";
	return false;
}

void HomeAutomation::setStateAppliance(RiceCooker* ap) {
	int i_input;
	char c_input;
	if (ap->getPowerFlag() == false) {
		cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
		cin >> c_input;
		while (c_input != 'Y' && c_input != 'y' && c_input != 'N' && c_input != 'n') {
			cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
			cin >> c_input;
		}
		if (c_input == 'N' || c_input == 'n') {
			return;
		}
		else
			ap->setPowerFlag(true);
	}
	cout << "������ ���� �Է�(1:������, 2:����, 3:������, 4:�����, 5.����) : ";
	cin >> i_input;
	while (i_input < 1 || i_input > 5) {
		cout << "������ ���� �Է�(1:������, 2:����, 3:������, 4:�����, 5.����) : ";
		cin >> i_input;
	}
	if (i_input <= 4) {
		ap->setMachineState(i_input);
	}
	else {
		ap->setPowerFlag(false);
	}
	return;
}