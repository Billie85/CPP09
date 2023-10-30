#include "PmergeMe.hpp"

//========Constructor========

Unit::Unit(){}//not use

Unit::Unit(int value):MainNumber(value),Index(-1),Haspair(false){}

Unit::~Unit(){}

//============operator============
Unit &Unit::operator=(const Unit &other)
{
	if(this != &other)
	{
		this->MainNumber = other.MainNumber;
		this->Index = other.Index;
		//this->prevOfset = other.prevOfset;
		this->Haspair = other.Haspair;
	}
	return(*this);
}
bool operator>(const Unit &a, const Unit &b)
{
	return (a.MainNumber > b.MainNumber);
}

bool operator<(const Unit &a, const Unit &b)
{
	return (a.MainNumber < b.MainNumber);
}

std::ostream &operator<<(std::ostream &os, const Unit &obj)
{
	os << obj.MainNumber;
	return(os);
}