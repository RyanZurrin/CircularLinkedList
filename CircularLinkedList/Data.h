#pragma once

#include "DataInterface.h"

inline data::data()
{
	name = "John/Jane doe";
	dob = "1/1/1900";
	balance = 00.00;
}

inline data::data(std::string n, std::string bd, double b)
{
	name = n;
	dob  = bd;
	balance = b;
}

inline std::string data::getName() const
{
	return name;
}

inline std::string data::getDOB() const
{
	return dob;
}

inline double data::getBalance() const
{
	return balance;
}

inline void data::setName(const std::string n)
{
	name = n;
}

inline void data::setDOB(const std::string bd)
{
	dob = bd;
}

inline void data::setBalance(const double b)
{
	balance = b;
}

inline void data::displayData()
{
	printf("\nname: %s \nDOB: %s \nBalance: %.2f\n",
		name.c_str(),
		dob.c_str(),
		balance);
}


