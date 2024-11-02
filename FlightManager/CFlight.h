#ifndef FLIGHT_H
#define FLIGHT_H

#include "CCrewMember.h"
#include "CFlightInfo.h"
#include "CCargo.h"
#include "CHost.h"
#include "CPilot.h"
#include <iostream>
using namespace std;

const int MAX_CREW = 5;

class CFlight {
private:
	CFlightInfo flightData;
	CPlane* plane;
	CCrewMember* crew[MAX_CREW];
	int currentCrewCount;

public:
	CFlight(const CFlightInfo& info, CPlane* assignedPlane = nullptr);
	CFlight(const CFlight& other);
	~CFlight();
	CFlightInfo* GetFlightInfo() { return &flightData; }
	void SetPlane(CPlane* newPlane);
	CPlane* AssignedPlane() const;
	CFlight& operator+(const CCrewMember& member);
	bool operator==(const CFlight& other) const;
	bool TakeOff();
	friend ostream& operator<<(ostream& out, const CFlight& flight);
};

#endif // FLIGHT_H