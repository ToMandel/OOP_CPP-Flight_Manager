#define _CRT_SECURE_NO_WARNINGS
#include "CCrewMember.h"
#include <cstring>

CCrewMember::CCrewMember(const char* _name, int _minutes) : name(NULL), minutes(_minutes) {
	if (_name) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
}

CCrewMember::CCrewMember(const CCrewMember& other) :minutes(other.minutes), name(NULL) {
	if (other.name) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
}

CCrewMember::~CCrewMember() {
	delete[] name;
}

CCrewMember& CCrewMember::operator=(const CCrewMember& other) {
	if (this != &other) {
		delete[] name;
		if (other.name) {
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
		}
		minutes = other.minutes;
	}
	return *this;
}

bool CCrewMember::operator+=(int additionalMinutes) {
	if (additionalMinutes < 0) {
		return false;
	}
	minutes += additionalMinutes;
	return true;
}

bool CCrewMember::operator==(const CCrewMember& other) const {
	int res = strcmp(name, other.name);
	if (res == 0) {
		return true;
	}
	else
		return false;
}

void CCrewMember::Present() const {
	cout << name << endl;
}
void CCrewMember::Uniform() const {
	cout << name << endl;
}

void CCrewMember::TakeOff(int minutes)
{
	this->minutes += minutes;
}

char* CCrewMember::GetName() const {
	return name;
}

ostream& operator<<(ostream& out, const CCrewMember& member) {
	out << member.name << " minutes " << member.minutes;
	return out;
}

void CCrewMember::Print(ostream& out) const
{
	out << "Crewmember " << name << " minutes " << minutes;
}