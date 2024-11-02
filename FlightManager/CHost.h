#pragma once
#include "CCrewMember.h"
#include <iostream>
using namespace std;

class CHost : public CCrewMember
{
public:
	enum Seniority { eRegular, eSuper, eCalcelan };

private:
	Seniority seniority;

public:

	CHost(const char* name, CHost::Seniority senType, int minutes = 0);
	CHost(const CHost& other);
	~CHost();

	CHost& operator=(const CHost& other);
	Seniority GetSeniority() const;
	const char* GetSeniorityName() const;
	virtual void Present() const;
	virtual void Uniform() const;
	virtual void TakeOff(int minutes);
	virtual void Print(ostream& out) const;
};