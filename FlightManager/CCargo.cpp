#include "CCargo.h"

CCargo::CCargo(int _seats, const char* _model, float maxWeight, float maxVolume) :CPlane(_seats, _model), currentWeight(0), currentVolume(0)
{
	this->maxVolume = maxVolume;
	this->maxWeight = maxWeight;
}

CCargo::CCargo(const CCargo& other) : CPlane(other), currentWeight(other.currentWeight), currentVolume(other.currentVolume)
{
	this->maxVolume = other.maxVolume;
	this->maxWeight = other.maxWeight;
}

CCargo::~CCargo()
{
}

CCargo& CCargo::operator=(const CCargo& other)
{
	if (this != &other)
	{
		CPlane::operator=(other);
		this->maxVolume = other.maxVolume;
		this->maxWeight = other.maxWeight;
	}
	return *this;
}

bool CCargo::Load(float weight, float volume)
{
	if (weight + currentWeight > maxWeight || volume + currentVolume > maxVolume)
	{
		return false;
	}
	currentWeight += weight;
	currentVolume += volume;
	return true;
}

void CCargo::CargoTakeOff(int minutes)
{
	cout << "Need to add " << minutes << " minutes to my log book" << endl;
}