#pragma once
#include <string>

class Data
{
public:
	Data();
	Data(std::string n, std::string bd, double b);
	std::string getName()const;
	std::string getDOB()const;
	double getBalance()const;
	void setName(const std::string n);
	void setDOB(const std::string bd);
	void setBalance(const double b);
	void displayData();

private:
	std::string name;
	std::string dob;
	double balance;

};
