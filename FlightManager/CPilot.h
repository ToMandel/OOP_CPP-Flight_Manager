#pragma once
#include "CCrewMember.h"
#include "CAddress.h"	
#include <iostream>
using namespace std;

class CPilot : public CCrewMember
{
private:
	bool bCaptain = false;
	CAddress address;	//address of the pilot
public:
	CPilot(const char* name, bool captain, const CAddress& address = CAddress(), int minutes = 0);
	CPilot(const CPilot& other);
	~CPilot();

	CPilot& operator=(const CPilot& other);
	virtual bool operator==(const CPilot& other) const;
	virtual bool operator+=(int additionalMinutes);

	virtual void ToSimulator() const;
	virtual void Present() const;
	virtual void Uniform() const;
	virtual void TakeOff(int minutes);
	virtual void Print(ostream& out) const;
};