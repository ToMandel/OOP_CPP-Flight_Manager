#ifndef FLIGHTCOMPANY_H
#define FLIGHTCOMPANY_H

#include "CCrewMember.h"
#include "CPilot.h"
#include "CHost.h"
#include "CFlight.h"
#include "CFlightInfo.h"
#include "CCargo.h"
#include <iostream>
using namespace std;

const int MAX_CREWS = 100;
const int MAX_PLANES = 50;
const int MAX_FLIGHTS = 200;

class CFlightCompany {
private:
	char* name;
	CCrewMember* crews[MAX_CREWS];
	CPlane* planes[MAX_PLANES];
	CFlight* flights[MAX_FLIGHTS];
	int currentCrewCount;
	int currentPlaneCount;
	int currentFlightCount;

public:
	CFlightCompany(const char* _name);
	~CFlightCompany();

	// No Copy Constructor as per instruction
	CFlightCompany& operator=(const CFlightCompany& other) = delete;
	bool IsCrewMemberExists(const CCrewMember& member) const;
	bool IsPlaneExists(const CPlane& plane) const;
	bool IsFlightExists(const CFlight& flight) const;
	bool AddCrewMember(CCrewMember& member);
	bool AddPlane(CPlane& plane);
	bool AddFlight(const CFlight& flight);
	CPlane* GetPlane(int index) const;
	CCrewMember* GetCrewMember(int index) const;
	void AddCrewToFlight(int flightNumber, char* workerName);
	int GetCargoCount() const;
	void PilotsToSimulator() const;
	void CrewGetPresent() const;
	void CrewGetUniform() const;
	CFlight* GetFlightByNum(int flightNumber) const;
	void TakeOff(int flightNumber);
	void Print(ostream& out) const;
	friend ostream& operator<<(ostream& out, const CFlightCompany& company);
};
#endif // FLIGHTCOMPANY_H