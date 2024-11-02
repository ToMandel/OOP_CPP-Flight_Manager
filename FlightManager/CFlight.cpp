#define _CRT_SECURE_NO_WARNINGS
#include "CFlight.h"
#include <cstring>

CFlight::CFlight(const CFlightInfo& info, CPlane* assignedPlane) : flightData(info), plane(assignedPlane), currentCrewCount(0) {
	for (int i = 0; i < MAX_CREW; i++) {
		crew[i] = nullptr;
	}
}

CFlight::CFlight(const CFlight& other) : flightData(other.flightData), plane(other.plane), currentCrewCount(other.currentCrewCount) {
	for (int i = 0; i < MAX_CREW; i++) {
		crew[i] = other.crew[i];  // assuming we're not duplicating the crew, but just pointing to the same members
	}
}

CFlight::~CFlight() {
}

void CFlight::SetPlane(CPlane* newPlane) {
	plane = newPlane;
}

CFlight& CFlight::operator+(const CCrewMember& member) {
	if (currentCrewCount < MAX_CREW) {
		crew[currentCrewCount] = const_cast<CCrewMember*>(&member);
		if (!crew[currentCrewCount]) {
			cout << "Debug: crew[" << currentCrewCount << "] is NULL after adding." << endl;
		}
		currentCrewCount++;
	}
	else {
		cout << "Debug: MAX_CREW reached, can't add more crew members." << endl;
	}
	return *this;
}


bool CFlight::operator==(const CFlight& other) const {
	return flightData == other.flightData;
}

bool CFlight::TakeOff() {
	int countPilots = 0;
	int countHosts = 0;
	int countSuper = 0;
	if (plane == NULL)
		return false;
	for (int i = 0; i < currentCrewCount; i++) {
		if (crew[i] != NULL) {
			if (!strcmp(typeid(*crew[i]).name() + 6, "CPilot")) {
				countPilots++;
			}
			else {
				countHosts++;
				if (((CHost*)crew[i])->GetSeniority() == CHost::eSuper) {
					countSuper++;
				}
			}
		}
	}
	if (!strcmp(typeid(*plane).name() + 6, "CCargo")) {
		if (countPilots > 0) {
			((CCargo*)plane)->CargoTakeOff(this->GetFlightInfo()->operator int());
			for (CCrewMember* member : crew) {
				if (member != NULL) {
					member->TakeOff(this->GetFlightInfo()->operator int());
				}
			}
			return true;
		}
	}
	else {
		if (countPilots == 1 && countHosts >= 0) {
			if (countSuper <= 1) {
				for (CCrewMember* member : crew) {
					if (member != NULL) {
						member->TakeOff(this->GetFlightInfo()->operator int());
					}
				}
				return true;
			}
		}
	}
	return false;
}

CPlane* CFlight::AssignedPlane() const {
	return this->plane;
}

ostream& operator<<(ostream& out, const CFlight& flight) {
	out << "Flight " << flight.flightData << endl;
	if (flight.plane) {
		out << *(flight.plane) << endl;
	}
	else {
		out << "No plane assign yet ";
	}
	out << " There are " << flight.currentCrewCount << " crew memebers in flight:" << endl;
	for (int i = 0; i < flight.currentCrewCount; i++) {
		CHost* host = dynamic_cast<CHost*>(flight.crew[i]);
		CPilot* pilot = dynamic_cast<CPilot*>(flight.crew[i]);
		if (host != nullptr) {
			host->Print(out);
		}
		else if (pilot != nullptr) {
			pilot->Print(out);
		}
	}
	return out;
}

