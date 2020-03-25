#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
#include "Robot.h"
#include <cstring>

int input(const char*);
void input(Robot *rp, int rcnt);
void work(Robot *rp, int rcnt);
void output(Robot *rp, int rcnt);

int main() {
	int rcnt;
	Robot *rp;
	rcnt = input("구입할 로봇 대수를 입력하시오 : ");
	rp = new Robot[rcnt];
	input(rp, rcnt);
	work(rp, rcnt);
	output(rp, rcnt);
	delete[] rp;
}

int input(const char *msg) {
	int num;
	cout << msg;
	cin >> num;
	return num;
}

void input(Robot *rp, int rcnt) {
	int e;
	char name[20];
	for (int i = 1; i <= rcnt; i++) {
		cout << "\n" << i << "번 로봇명을 입력하시오 : ";
		cin >> name;
		rp[i - 1].setName(name);
		cout << rp[i - 1].getName() << "의 에너지 양을 입력하시오 : ";
		cin >> e;
		rp[i - 1].setEnergy(e);
	}
	cin.ignore();
}

void work(Robot *rp, int rcnt) {
	int i, input, e;
	char tname[100];
	while (1) {
		cout << "\n# 로봇명 선택(";
		for (i = 0; i < rcnt; i++)
			cout << rp[i].getName() << ", ";
		cout << "\b\b) : ";
		cin.getline(tname, sizeof(tname));
		if (strcmp(tname, "") == 0) {
			cout << "종료\n";
			return;
		}
		for (i = 0; i < rcnt; i++) {
			if (strcmp(tname, rp[i].getName()) == 0)
				break;
		}
		if (i == rcnt) {
			cout << "없는 로봇입니다. 재입력하세요!\n";
			continue;
		}
		else {
			cout << "# 할일 선택(1.전진/2.후진/3.회전/4.점프/5.충전) : ";
			cin >> input;
			while (input < 1 || input>5 || cin.fail()) {
				cin.clear();
				while (cin.get() != '\n')
					;
				cout << "# 할일 선택(1.전진/2.후진/3.회전/4.점프/5.충전) : ";
				cin >> input;
			}
			switch (input) {
			case 1: rp[i].go(); break;
			case 2: rp[i].back(); break;
			case 3: rp[i].turn(); break;
			case 4: rp[i].jump(); break;
			case 5: cout << "# 충전할 에너지양 입력 : "; cin >> e; rp[i].charge(e);
			}
		}
		cin.ignore();
	}
}

void output(Robot *rp, int rcnt) {
	for (int i = 0; i < rcnt; i++) {
		cout << i + 1 << ". " << rp[i].getName() << " : " << rp[i].getEnergy() << endl;
	}
}
void Robot::errPrn() {
		cout << "에너지가 부족합니다.\n";
}

Robot::Robot() {
	this->name = new char[1];
	strcpy(name, "");
	this->energy = 0;
}

Robot::~Robot() {
	delete[] this->name;
}

Robot::Robot(const char *name, int energy) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->energy = energy;
}

Robot::Robot(const Robot& r) {
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->energy = r.energy;
}

void Robot::go() {
	if (this->energy >= 10) {
		cout << this->name << " 전진...\n";
		this->energy -= 10;
	}
	else
		errPrn();
}

void Robot::back() {
	if (this->energy >= 20) {
		cout << this->name << " 후진...\n";
		this->energy -= 20;
	}
	else
		errPrn();
}

void Robot::turn() {
	if (this->energy >= 30) {
		cout << this->name << " 턴...\n";
		this->energy -= 30;
	}
	else
		errPrn();
}

void Robot::jump() {
	if (this->energy >= 40) {
		cout << this->name << " 점프...\n";
		this->energy -= 40;
	}
	else
		errPrn();
}

void Robot::charge(int e) {
	if (e < 0)
		cout << "음수로는 충전불가...\n";
	else {
		cout << this->name << "에너지 " << e << " 충전\n";
		this->energy += e;
	}
}

char* Robot::getName() {
	return this->name;
}

void Robot::setName(const char *name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

int Robot::getEnergy() {
	return this->energy;
}

void Robot::setEnergy(int e) {
	if (e < 0)
		this->energy = 0;
	else
		this->energy = e;
}
