#define _CRT_SECURE_NO_WARNINGS
#include "CFlightInfo.h"
#include <cstring>

CFlightInfo::CFlightInfo(const char* _destination, int _flightNumber, int _flightMinutes, int _km)
	: destination(NULL), flightNumber(_flightNumber), flightMinutes(_flightMinutes), km(_km) {
	if (_destination) {
		destination = new char[strlen(_destination) + 1];
		strcpy(destination, _destination);
	}
}

CFlightInfo::CFlightInfo(const CFlightInfo& other)
	: CFlightInfo(other.destination, other.flightNumber, other.flightMinutes, other.km) {}

CFlightInfo::~CFlightInfo() {
	delete[] destination;
}

CFlightInfo& CFlightInfo::operator=(const CFlightInfo& other) {
	if (this != &other) {
		delete[] destination;
		flightNumber = other.flightNumber;
		flightMinutes = other.flightMinutes;
		km = other.km;
		if (other.destination) {
			destination = new char[strlen(other.destination) + 1];
			strcpy(destination, other.destination);
		}
	}
	return *this;
}

bool CFlightInfo::operator!=(const CFlightInfo& other) const {
	return flightNumber != other.flightNumber;
}

CFlightInfo::operator int() const {
	return flightMinutes;
}

ostream& operator<<(ostream& out, const CFlightInfo& flightInfo) {
	out << "Flight Info dest: " << flightInfo.destination << " Number "
		<< flightInfo.flightNumber << " minutes " << flightInfo.flightMinutes
		<< " KM " << flightInfo.km << endl;
	return out;
}


int CFlightInfo::GetFNum() const {
	return flightNumber;
}
