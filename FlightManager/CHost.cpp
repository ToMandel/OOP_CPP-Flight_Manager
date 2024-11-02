#include "CHost.h"


CHost::CHost(const char* name, CHost::Seniority senType, int minutes) : CCrewMember(name, minutes) {
	this->seniority = senType;
}

CHost::CHost(const CHost& other) : CCrewMember(other)
{
	this->seniority = other.seniority;
}

CHost::~CHost()
{
}

CHost& CHost::operator=(const CHost& other)
{
	if (this != &other)
	{
		CCrewMember::operator=(other);
		this->seniority = other.seniority;
	}
	return *this;
}

void CHost::TakeOff(int minutes)
{
	this->minutes += minutes;
}

void CHost::Present() const
{
	cout << name << " thanking the company for receiving the holiday gift.\nI wasn't expecting it" << endl;
}

void CHost::Uniform() const
{
	cout << " I think the new uniform is very nice!" << endl;
}

CHost::Seniority CHost::GetSeniority() const
{
	return this->seniority;
}

const char* CHost::GetSeniorityName() const
{
	switch (this->seniority) {
	case (eRegular):
		return "Regular";
		break;
	case (eSuper):
		return "Super";
		break;
	case (eCalcelan):
		return "Calcelan";
		break;
	default:
		break;
	}
}

void CHost::Print(ostream& out) const
{
	out << "Host " << this->GetSeniorityName() << " ";
	out << static_cast<const CCrewMember&>(*this) << endl;
}