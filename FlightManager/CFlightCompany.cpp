#define _CRT_SECURE_NO_WARNINGS
#include "CFlightCompany.h"
#include <cstring>

CFlightCompany::CFlightCompany(const char* _name) : name(NULL), currentCrewCount(0), currentPlaneCount(0), currentFlightCount(0) {
	if (_name) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
}

CFlightCompany::~CFlightCompany() {
	delete[] name;
	for (int i = 0; i < currentFlightCount; i++) {
		delete flights[i];
	}
	for (int i = 0; i < currentCrewCount; i++) {
		delete crews[i];
	}
	for (int i = 0; i < currentPlaneCount; i++) {
		delete planes[i];
	}
}
bool CFlightCompany::IsCrewMemberExists(const CCrewMember& member) const {
	for (int i = 0; i < currentCrewCount; i++) {
		if (strcmp(crews[i]->GetName(), member.GetName()) == 0) {
			return true;
		}
	}
	return false;
}


bool CFlightCompany::AddCrewMember(CCrewMember& member) {
	if (IsCrewMemberExists(member)) {
		return false;
	}
	if (currentCrewCount < MAX_CREWS) {
		if (dynamic_cast<CPilot*>(&member) != nullptr) {
			crews[currentCrewCount++] = new CPilot(*dynamic_cast<CPilot*>(&member));
			return true;
		}
		else {
			crews[currentCrewCount++] = new CHost(*dynamic_cast<CHost*>(&member));
			return true;
		}
	}
	return false;
}

bool CFlightCompany::IsPlaneExists(const CPlane& plane) const {
	for (int i = 0; i < currentPlaneCount; i++) {
		if (planes[i]->getPlaneID() == plane.getPlaneID()) {
			return true;
		}
	}
	return false;
}

bool CFlightCompany::IsFlightExists(const CFlight& flight) const {
	for (int i = 0; i < currentFlightCount; i++) {
		if (*flights[i] == flight) {
			return true;
		}
	}
	return false;
}

bool CFlightCompany::AddPlane(CPlane& plane) {
	if (IsPlaneExists(plane))
	{
		return false;
	}
	if (currentPlaneCount < MAX_PLANES) {
		CCargo* cargo = dynamic_cast<CCargo*>(&plane);
		if (cargo != nullptr) {
			planes[currentPlaneCount++] = new CCargo(*cargo);
		}
		else {
			planes[currentPlaneCount++] = new CPlane(plane);
		}
		return true;
	}
	return false;
}


bool CFlightCompany::AddFlight(const CFlight& flight) {
	if (IsFlightExists(flight))
	{
		return false;
	}
	if (currentFlightCount < MAX_FLIGHTS) {
		flights[currentFlightCount++] = new CFlight(flight);
		return true;
	}
	return false;
}

CPlane* CFlightCompany::GetPlane(int index) const {
	if (index >= 0 && index < currentPlaneCount) {
		return planes[index];
	}
	return nullptr;
}

CCrewMember* CFlightCompany::GetCrewMember(int index) const {
	if (index >= 0 && index < currentCrewCount) {
		return crews[index];
	}
	return nullptr;
}

void CFlightCompany::AddCrewToFlight(int flightNumber, char* workerName) {
	for (int i = 0; i < currentFlightCount; i++) {
		if (flights[i]->GetFlightInfo()->GetFNum() == flightNumber) {
			for (int j = 0; j < currentCrewCount; j++) {
				if (crews[j]->GetName() == name) {
					*(flights[i]) + *(crews[j]);
					break;
				}
			}
			break;
		}
	}

}

int CFlightCompany::GetCargoCount() const {
	int count = 0;
	for (int i = 0; i < currentPlaneCount; i++) {
		if (dynamic_cast<CCargo*>(planes[i]) != nullptr) {
			count++;
		}
	}
	return count;

}

void CFlightCompany::PilotsToSimulator() const {
	for (int i = 0; i < currentCrewCount; i++) {
		if (dynamic_cast<CPilot*>(crews[i]) != nullptr) {
			dynamic_cast<CPilot*>(crews[i])->ToSimulator();
		}
	}
}
void CFlightCompany::CrewGetPresent() const {
	for (int i = 0; i < currentCrewCount; i++) {
		crews[i]->Present();
	}
}
void CFlightCompany::CrewGetUniform() const {
	for (int i = 0; i < currentCrewCount; i++) {
		crews[i]->Uniform();
	}
}

CFlight* CFlightCompany::GetFlightByNum(int flightNumber) const {
	for (int i = 0; i < currentFlightCount; i++) {
		if (flights[i]->GetFlightInfo()->GetFNum() == flightNumber) {
			return flights[i];
		}
	}
	return nullptr;
}

void CFlightCompany::TakeOff(int flightNumber)
{
	CFlight* flight = GetFlightByNum(flightNumber);
	if (flight) {
		flight->TakeOff();
	}
}



ostream& operator<<(ostream& out, const CFlightCompany& company) {
	out << "Flight company: " << company.name << endl;
	out << "There are " << company.currentCrewCount << " Crew members:" << endl;
	for (int i = 0; i < company.currentCrewCount; i++) {
		if (dynamic_cast<CPilot*>(company.crews[i]) != nullptr)
			dynamic_cast<CPilot*>(company.crews[i])->Print(out);
		else
		{
			dynamic_cast<CHost*>(company.crews[i])->Print(out);
		}
	}

	out << "There are " << company.currentPlaneCount << " Planes:" << endl;
	for (int i = 0; i < company.currentPlaneCount; i++) {
		out << *(company.planes[i]) << endl;
	}

	out << "There are " << company.currentFlightCount << " Flights:" << endl;
	for (int i = 0; i < company.currentFlightCount; i++) {
		out << *(company.flights[i]) << endl;
	}

	return out;
}

void CFlightCompany::Print(ostream& out) const {
	out << *this;
}
