#pragma once
#include "HomeAutomation.h"

HomeAutomation::HomeAutomation() {
	for (int i = 0; i < APPLIANCE_MAX_CNT; i++) {
		applianceArray[i] = NULL;
	}
	applianceCnt = 0;
}

HomeAutomation::HomeAutomation(const HomeAutomation& r) {
	RiceCooker* rp;
	Washer* wp;
	AirConditioner* ap;
	applianceCnt = r.applianceCnt;
	for (int i = 0; i < applianceCnt; i++) {
		if (rp=dynamic_cast<RiceCooker*>(r.applianceArray[i]))
			applianceArray[i] = new RiceCooker(*rp);
		else if(wp=dynamic_cast<Washer*>(r.applianceArray[i]))
			applianceArray[i] = new Washer(*wp);
		else if(ap = dynamic_cast<AirConditioner*>(r.applianceArray[i]))
			applianceArray[i] = new AirConditioner(*ap);
	}
}

HomeAutomation::~HomeAutomation() {
	for (int i = 0; i < applianceCnt; i++) {
		delete applianceArray[i];
	}
}

Appliance **HomeAutomation::getApplianceArray() {
	return applianceArray;
}

int HomeAutomation::getApplianceCnt() const {
	return applianceCnt;
}

HomeAutomation& HomeAutomation::operator=(const HomeAutomation& r) {
	if (this == &r)
		return *this;
	for (int i = 0; i < applianceCnt; i++) {
		delete applianceArray[i];
	}
	applianceCnt = r.applianceCnt;
	for (int i = 0; i < applianceCnt; i++) {
		if (dynamic_cast<RiceCooker*>(r.applianceArray[i]) != NULL)
			applianceArray[i] = new RiceCooker(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
		else if (dynamic_cast<Washer*>(r.applianceArray[i]) != NULL)
			applianceArray[i] = new Washer(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
		else
			applianceArray[i] = new AirConditioner(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
	}
	return *this;
}

bool HomeAutomation::addAppliance(Appliance *ap) {
	if (applianceCnt >= APPLIANCE_MAX_CNT)
		return false;
	for (int i = 0; i < applianceCnt; i++) {
		if (applianceArray[i]->getMachineName() == ap->getMachineName()) {
			cout << "������ �̸��� ��ǰ ��� �Ұ�\n";
			return false;
		}
	}
	if (dynamic_cast<RiceCooker*>(ap) != NULL)
		applianceArray[applianceCnt] = new RiceCooker(ap->getMachineName(), ap->getPowerConsumption());
	else if (dynamic_cast<Washer*>(ap) != NULL)
		applianceArray[applianceCnt] = new Washer(ap->getMachineName(), ap->getPowerConsumption());
	else
		applianceArray[applianceCnt] = new AirConditioner(ap->getMachineName(), ap->getPowerConsumption());
	applianceCnt++;
	return true;
}

int HomeAutomation::searchMachine(string machineName) {
	for (int i = 0; i < applianceCnt; i++) {
		if (applianceArray[i]->getMachineName() == machineName) {
			return i;
		}
	}
	return -1;
}

bool HomeAutomation::deleteAppliance(string machineName) {
	for (int i = 0; i < applianceCnt; i++) {
		if (applianceArray[i]->getMachineName() == machineName) {
			delete applianceArray[i];
			for (int j = i; j < applianceCnt - 1; j++) {
				applianceArray[j] = applianceArray[j + 1];
			}
			applianceCnt--;
			return true;
		}
	}
	return false;
}

void HomeAutomation::listDisplayAppliance() {
	for (int i = 0; i < applianceCnt; i++) {
		applianceArray[i]->stateView();
	}
}

bool HomeAutomation::controlAppliance(string machineName) {
	char c_input;
	for (int i = 0; i < applianceCnt; i++) {
		if (applianceArray[i]->getMachineName() == machineName) {
			if (applianceArray[i]->getPowerFlag() == false) {
				cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
				cin >> c_input;
				while (c_input != 'Y' && c_input != 'y' && c_input != 'N' && c_input != 'n') {
					cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
					cin >> c_input;
				}
				if (c_input == 'N' || c_input == 'n') {
					return true;
				}
				else {
					applianceArray[i]->turnOn();
				}
			}
			setStateAppliance(applianceArray[i]);
			return true;
		}
	}
	cout << "** �ش��ϴ� ��ǰ�� �������� �ʽ��ϴ�.\n";
	return false;
}

void HomeAutomation::setStateAppliance(Appliance *ap) {
	int i_input;

	RiceCooker *ricep;
	Washer* washp;
	AirConditioner *airp;
	
	if (ricep = dynamic_cast<RiceCooker*>(ap)) {
		cout << "1:������, 2:����, 3:������, 4:�����, 5.���� : ";
		cin >> i_input;
		while (i_input < 1 || i_input > 5) {
			cout << "1:������, 2:����, 3:������, 4:�����, 5.���� : ";
			cin >> i_input;
		}
		dynamic_cast<RiceCooker*>(ap)->setMachineState(i_input);
		if (i_input == 5) {
			ricep->turnOff();
		}
		else {
			ricep->turnOn();
		}
		return;
	}

	else if (airp = dynamic_cast<AirConditioner*>(ap)) {
		cout << "1.��ǳ / 2.�ù� / 3.���� / 4.���� : ";
		cin >> i_input;
		while (i_input < 1 || i_input > 4) {
			cout << "1.��ǳ / 2.�ù� / 3.���� / 4.���� : ";
			cin >> i_input;
		}
		airp->setMachineState(i_input);
		if (i_input == 4) {
			airp->turnOff();
			return;
		}
		else {
			airp->turnOn();
		}
		i_input = 0;
		while (i_input != 3) {
			cout << "1.�µ� �ø��� / 2.�µ� ������ / 3.�µ����� ���� : ";
			cin >> i_input;
			while (i_input < 1 || i_input > 3) {
				cout << "1.�µ� �ø��� / 2.�µ� ������ / 3.�µ����� ���� : ";
				cin >> i_input;
			}
			switch (i_input) {
			case 1 : ++*airp; break;
			case 2 : -- * airp; break;
			case 3: return;
			}
		}
	}
	else if(washp = dynamic_cast<Washer*>(ap)) {
		cout << "1.������ / 2.�Ϲݻ��� / 3.�������� / 4.���� / 5.���� : ";
		cin >> i_input;
		while (i_input < 1 || i_input > 5) {
			cout << "1.������ / 2.�Ϲݻ��� / 3.�������� / 4.���� / 5.���� : ";
			cin >> i_input;
		}
		washp->setMachineState(i_input);
		if (i_input == 5) {
			washp->turnOff();
			return;
		}
		else {
			washp->turnOn();
		}
	}
}