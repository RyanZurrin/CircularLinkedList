#pragma once

#include "DataInterface.h"

inline Data::Data()
{
	name = "John/Jane doe";
	dob = "1/1/1900";
	balance = 00.00;
}

inline Data::Data(std::string n, std::string bd, double b)
{
	name = n;
	dob  = bd;
	balance = b;
}

inline std::string Data::getName() const
{
	return name;
}

inline std::string Data::getDOB() const
{
	return dob;
}

inline double Data::getBalance() const
{
	return balance;
}

inline void Data::setName(const std::string n)
{
	name = n;
}

inline void Data::setDOB(const std::string bd)
{
	dob = bd;
}

inline void Data::setBalance(const double b)
{
	balance = b;
}

inline void Data::displayData()
{
	printf("\nname: %s \nDOB: %s \nBalance: %.2f\n",
		name.c_str(),
		dob.c_str(),
		balance);
}


