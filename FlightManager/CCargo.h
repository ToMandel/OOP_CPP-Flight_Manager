#pragma once
#include "CPlane.h"	
#include <iostream>
using namespace std;

class CCargo : public CPlane
{
private:
	float maxWeight;
	float maxVolume;
	float currentWeight;
	float currentVolume;
public:

	CCargo(int _seats, const char* _model, float maxWeight, float maxVolume);
	CCargo(const CCargo& other);
	virtual ~CCargo();
	CCargo& operator=(const CCargo& other);
	bool Load(float weight, float volume);
	void CargoTakeOff(int minutes);
	virtual void Print(ostream& os) const
	{
		os <<
			"Cargo M_vol " << maxVolume << " M_Kg " << maxWeight << " C_vol " << currentVolume << " C_Kg " << currentWeight << endl;
	}
};