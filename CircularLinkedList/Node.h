#pragma once
#include "Data.h"
/*
typedef struct data
{
	char toolname[35];
	int quantity;
	double cost;
	void displayData();
};
*/

struct node
{
	int key = -1;
	data d;
	//data d;
	node* next = NULL;

};