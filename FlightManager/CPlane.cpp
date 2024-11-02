#define _CRT_SECURE_NO_WARNINGS
#include "CPlane.h"
#include <cstring>

int CPlane::nextID = CPlane::START_ID;

CPlane::CPlane(int _seats, const char* _model) : seats(_seats), model(NULL), id(nextID++) {
	if (_model) {
		model = new char[strlen(_model) + 1];
		strcpy(model, _model);
	}
}

CPlane::CPlane(const CPlane& other) : seats(other.seats), model(NULL), id(other.id) {
	if (other.model) {
		model = new char[strlen(other.model) + 1];
		strcpy(model, other.model);
	}
}

CPlane::~CPlane() {
	delete[] model;
}

CPlane& CPlane::operator=(const CPlane& other) {
	if (this != &other) {
		delete[] model;
		model = NULL;
		seats = other.seats;
		id = other.id;
		if (other.model) {
			model = new char[strlen(other.model) + 1];
			strcpy(model, other.model);
		}
	}
	return *this;
}

int CPlane::getPlaneID() const {
	return id;
}
char* CPlane::getPlaneModel() const {
	return model;
}
CPlane& CPlane::operator++() {
	seats++;
	return *this;
}

CPlane CPlane::operator++(int) {
	CPlane tmp(*this);
	seats++;
	return tmp;
}

ostream& operator<<(ostream& out, const CPlane& plane) {
	out << "Plane " << plane.id << " degem " << plane.model << " seats " << plane.seats << endl;
	plane.Print(out);
	return out;
}