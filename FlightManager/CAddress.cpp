#define _CRT_SECURE_NO_WARNINGS
#include "CAddress.h"
#include <cstring>

CAddress::CAddress(int _houseNumber, const char* _street, const char* _city)
	: houseNumber(_houseNumber), street(NULL), city(NULL) {
	if (_street) {
		street = new char[strlen(_street) + 1];
		strcpy(street, _street);
	}
	if (_city) {
		city = new char[strlen(_city) + 1];
		strcpy(city, _city);
	}
}

CAddress::CAddress(const CAddress& other)
	: CAddress(other.houseNumber, other.street, other.city) {}

CAddress::~CAddress() {
	delete[] street;
	delete[] city;
}

CAddress& CAddress::operator=(const CAddress& other) {
	if (this != &other) {
		delete[] street;
		delete[] city;
		houseNumber = other.houseNumber;
		if (other.street) {
			street = new char[strlen(other.street) + 1];
			strcpy(street, other.street);
		}
		if (other.city) {
			city = new char[strlen(other.city) + 1];
			strcpy(city, other.city);
		}
	}
	return *this;
}

bool CAddress::operator==(const CAddress& other) const {
	return houseNumber == other.houseNumber &&
		strcmp(street, other.street) == 0 &&
		strcmp(city, other.city) == 0;
}

bool CAddress::operator!=(const CAddress& other) const {
	return !(*this == other);
}

istream& operator>>(istream& in, CAddress& addr) {
	cout << "Please enter house number, street name, and city name: " << endl;
	in >> addr.houseNumber;
	in.ignore(); // to skip newline/whitespace

	const int BUFFER_SIZE = 256;
	char buffer[BUFFER_SIZE];

	// Read street
	in.get(buffer, BUFFER_SIZE);
	addr.street = new char[strlen(buffer) + 1];
	strcpy(addr.street, buffer);

	in.ignore(); // to skip newline/whitespace

	// Read city
	in.get(buffer, BUFFER_SIZE);
	addr.city = new char[strlen(buffer) + 1];
	strcpy(addr.city, buffer);

	return in;
}


ostream& operator<<(ostream& out, const CAddress& addr) {
	out << addr.street << " " << addr.houseNumber << " " << addr.city;
	return out;
}

const char* CAddress::GetCurrentAddress() const {
	// Returns a formatted string (you might need more advanced handling here)
	return street;
}
