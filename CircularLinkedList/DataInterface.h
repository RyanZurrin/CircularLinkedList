#pragma once
#include <string>

struct data
{
public:
	data();
	data(std::string n, std::string bd, double b);
	std::string getName()const;
	std::string getDOB()const;
	double getBalance()const;
	void setName(const std::string n);
	void setDOB(const std::string bd);
	void setBalance(const double b);
	void displayData();
	std::string name;
	std::string dob;
	double balance;

};
