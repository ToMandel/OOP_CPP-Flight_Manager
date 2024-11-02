#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <iostream>
using namespace std;

class CCrewMember {
public:
protected:
	static int nextID;
	char* name;
	int minutes;

public:
	CCrewMember(const char* _name, int _minutes = 0);
	CCrewMember(const CCrewMember& other);
	~CCrewMember();

	CCrewMember& operator=(const CCrewMember& other);
	virtual bool operator+=(int additionalMinutes);
	virtual bool operator==(const CCrewMember& other) const;
	friend ostream& operator<<(ostream& out, const CCrewMember& member);
	char* GetName() const;
	virtual void Present() const;
	virtual void Uniform() const;
	virtual void TakeOff(int minutes);
	virtual void Print(ostream& out) const;
};
#endif // CREWMEMBER_H