#ifndef FLIGHTINFO_H
#define FLIGHTINFO_H

#include <iostream>
using namespace std;

class CFlightInfo {
private:
	char* destination;
	int flightNumber;
	int flightMinutes;
	int km;

public:
	CFlightInfo(const char* _destination, int _flightNumber, int _flightMinutes, int _km);
	CFlightInfo(const CFlightInfo& other);
	~CFlightInfo();

	CFlightInfo& operator=(const CFlightInfo& other);
	bool operator!=(const CFlightInfo& other) const;
	operator int() const;

	friend ostream& operator<<(ostream& out, const CFlightInfo& flightInfo);

	int GetFNum() const;
};

#endif // FLIGHTINFO_H