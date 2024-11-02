#include "CPilot.h"


CPilot::CPilot(const char* name, bool captain, const CAddress& address, int minutes) : CCrewMember(name, minutes)
{
	this->address = address;
	this->bCaptain = captain;
}

CPilot::CPilot(const CPilot& other) : CCrewMember(other)
{
	this->address = other.address;
	this->bCaptain = other.bCaptain;
}

CPilot::~CPilot()
{
}

CPilot& CPilot::operator=(const CPilot& other)
{
	if (this != &other)
	{
		CCrewMember::operator=(other);
		this->address = other.address;
		this->bCaptain = other.bCaptain;
	}
	return *this;
}

bool CPilot::operator==(const CPilot& other) const
{
	return CCrewMember::operator==(other) && this->address == other.address;
}

bool CPilot::operator+=(int additionalMinutes)
{
	if (additionalMinutes < 0)
		return false;
	if (bCaptain)
		this->minutes += (additionalMinutes * 1.1);
	else
		this->minutes += additionalMinutes;

	return true;
}

void CPilot::TakeOff(int minutes)
{
	this->minutes += minutes;
}

void CPilot::ToSimulator() const
{
	cout << "Pilot " << name << "got the message will come soon" << endl;
}

void CPilot::Present() const
{
	cout << name << " thanking the company for receiving the holiday gift." << endl;
}

void CPilot::Uniform() const
{
	cout << name << " this is the fifth time I get a new uniform - this is a waste of money" << endl;
}

void CPilot::Print(ostream& out) const
{
	out << "Pilot ";
	out << static_cast<const CCrewMember&>(*this);
	if (address.GetCurrentAddress() != NULL)
		out << " Home: " << address << endl;
	if (!bCaptain)
		out << "Not a captain" << endl;
	else
		out << " a Captain" << endl;
}