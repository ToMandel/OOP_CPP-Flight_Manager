#ifndef PLANE_H
#define PLANE_H

#include <iostream>
using namespace std;

class CPlane {
public:
	static const int START_ID = 100;

protected:
	static int nextID;
	int id;
	int seats;
	char* model;

public:
	CPlane(int _seats, const char* _model);
	CPlane(const CPlane& other);
	virtual ~CPlane();

	CPlane& operator=(const CPlane& other);
	CPlane& operator++();
	CPlane operator++(int);
	int getPlaneID() const;
	char* getPlaneModel() const;
	virtual void Print(ostream& os) const {};
	friend ostream& operator<<(ostream& out, const CPlane& plane);
};

#endif // PLANE_H