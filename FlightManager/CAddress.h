#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
using namespace std;

class CAddress {
private:
	int houseNumber;
	char* street;
	char* city;

public:
	CAddress(int _houseNumber = 0, const char* _street = NULL, const char* _city = NULL);
	CAddress(const CAddress& other);
	~CAddress();

	CAddress& operator=(const CAddress& other);
	bool operator==(const CAddress& other) const;
	bool operator!=(const CAddress& other) const;

	friend istream& operator>>(istream& in, CAddress& addr);
	friend ostream& operator<<(ostream& out, const CAddress& addr);
	const char* GetCurrentAddress() const;
};
#endif // ADDRESS_H