#pragma once
#include <iostream>
#include <utility>

#include "CircularLinked.h"

inline CircularLinkedList::CircularLinkedList()//tested and working
{
	//std::cout << "in the default constructor" << std::endl;
	qty = 0;
	max = INT_MAX;
	start = NULL;
	curr = NULL;
}//end no argument constructor

inline CircularLinkedList::CircularLinkedList(int maxSize)//tested and working
{
	//std::cout << "in overloaded constructor"<<std::endl;
	qty = 0;
	if (maxSize > 0)
	{
		max = maxSize;
	}
	else
		max = INT_MAX;

	start = NULL;
	curr = NULL;
}//end overloaded constructor

inline bool CircularLinkedList::addItem(int val, Data _d)//tested and working
{
	Node* temp;

	if (isFull())
	{
		//std::cout << "cant add list is full" << std::endl;
		return false;
	}
	temp      = new Node;
	temp->key = val;
	temp->d   = _d;
	curr      = start;
	if (isEmpty())
	{
		//std::cout << "adding first node: "<< val << std::endl;
		temp->next = temp;
		start = temp;
		curr = start;
		qty++;
		return true;
	}
	else if (curr->key >= temp->key)
	{
		//std::cout << "adding new first node: "<<val << std::endl;
		if(start->key == val)
		{
			//std::cout << "duplicate key not added: " << val << std::endl;
			return false;
		}
		while (curr->next != start)
		{
			curr = curr->next;
		}
		curr->next = temp;
		temp->next = start;
		start = temp;
		qty++;
		return true;
	}
	else
	{
		//std::cout << "adding node to middle of list: " << val << std::endl;
		while (curr->next != start && curr->next->key <= temp->key)
		{
			if (curr->next->key == val)
			{
				//std::cout << "duplicate key not added: " << val << std::endl;
				return false;
			}
			curr = curr->next;
		}
		temp->next = curr->next;
		curr->next = temp;
		qty++;
		return true;
	}
}//end addItem

inline bool CircularLinkedList::deleteItem(int val, Data& _d)//tested and working
{
	Node* temp;
	if(isEmpty()) {
		//std::cout <<" list not initialized." << std::endl;
		return false;
	}
	if(start->key == val) {
		//std::cout << "deleting start key"<<std::endl;

			curr = start;
			while(curr->next!=start) {
				curr = curr->next;
			}
			if (curr->key == val)
			{
				//std::cout << "deleting only node: "<<val<<std::endl;
				temp = start;
				_d = temp->d;
				delete temp;
				start = curr = NULL;
				qty--;
				return true;
			}
			else
			{
				//std::cout << "deleting first node: " << val << std::endl;
				temp = start;
				start = start->next;
				curr->next = start;
				_d = temp->d;
				delete temp;
				qty--;
				return true;
			}

	}
	else if(start->key != val && start->next == start) {
		//std::cout << val <<" not found in the list." << std::endl;
		return false;
	}
	curr = start->next;
	while(curr != start && curr->next->key != val) {
		curr = curr->next;
	}
	if(curr->next->key == val && curr) {
		//std::cout << "deleting node in list: "<< val << std::endl;
		temp = curr->next;
		curr->next = temp->next;
		_d = temp->d;
		delete temp;
		qty--;
		return true;
	}else
	{
		//std::cout << val <<" not found in the list." << std::endl;
		return false;
	}

}//end deleteItem


inline bool CircularLinkedList::getItem(int val, Data& _d)//tested and working
{

	if (isEmpty())
	{
		//std::cout << "in getItem and is empty list" << std::endl;
		return false;
	}
	if (start->key == val)
	{
		//std::cout << "item found at start of list: "<<val <<std::endl;
		_d = start->d;
		return true;
	}

	curr = start->next;
	if (curr->key == val)
	{
		//std::cout << "item found second slot: "<<val<<std::endl;
		_d = curr->d;
		return true;
	}
	else
	{
		//std::cout << "in getItem else statement now"<<std::endl;
		while (curr != start)
		{
			//std::cout<< "val: "<< val << " in while loop checking curr: "<< curr->key<<std::endl;
			if (val == curr->key)
			{
				//std::cout << "getItem found: " << val << std::endl;
				_d = curr->d;
				return true;
			}
			curr = curr->next;
		}
		//std::cout << "leaving getItem else statement now"<<std::endl;
	}
	//std::cout << "in getItem and item was not found: "<< val << std::endl;
	return false;
}//end getItem

inline bool CircularLinkedList::inList(const int val)
{
	if (isEmpty())
	{
		//std::cout << "in inList and is empty list" << std::endl;
		return false;
	}
	if (start->key == val)
	{
		//std::cout << "item found at start of list: "<<val <<std::endl;
		return true;
	}

	curr = start->next;
	if (curr->key == val)
	{
		//std::cout << "item found second slot: "<<val<<std::endl;
		return true;
	}
	else
	{
		//std::cout << "in inList else statement now"<<std::endl;
		while (curr != start)
		{
			//std::cout<< "val: "<< val << " in while loop checking curr: "<< curr->key<<std::endl;
			if (val == curr->key)
			{
				//std::cout << "getItem found: " << val << std::endl;
				return true;
			}
			curr = curr->next;
		}
		//std::cout << "leaving getItem else statement now"<<std::endl;
	}
	////std::cout << "in getItem and item was not found: "<< val << std::endl;
	return false;
}//end inList

inline int CircularLinkedList::getQty()const//tested and working
{
	//std::cout << "in get qty" << std::endl;
	return qty;
}//end getQty

inline bool CircularLinkedList::isFull()const//tested and working
{
	//std::cout << "in isFull" << std::endl;
	return (qty==max);
}//end isFull

inline bool CircularLinkedList::isEmpty()const//tested and working
{
	//std::cout << "in isEmpty" << std::endl;
	return (qty == 0);
}//end isEmpty

inline bool CircularLinkedList::makeEmpty()//tested and working
{
	Node* temp;
	for (; curr->next != start; curr = curr->next){}
	if (qty == 0)
	{
		//std::cout << "in makeEmpty and already empty" << std::endl;
		return false;
	}
	while (qty != 0)
	{
		//std::cout << "qty: " << qty << std::endl;
		//std::cout << "in makeEmpty deleting key: " << start->key
		//		  << std::endl;
		temp = start;
		start = start->next;
		delete temp;
		curr = start;
		qty--;
		//std::cout << "qty: " << qty << std::endl;

	}
	start = curr = NULL;
	return true;
}//end makeEmpty

inline void CircularLinkedList::displayKeys()const//tested and working
{
	Node* printer;

	if(start != NULL)
	{
		printer = start;
		std::cout << std::endl;
		do {
			std::cout<<printer->key<<"->";
		printer = printer->next;
		} while(printer != start);
	}
	std::cout << std::endl;
}//end displayKeys

inline void CircularLinkedList::displayData(const int _key = -1)
{
	//std::cout << "in data printer start"<<std::endl;
	Node* dPrinter;
	if (start == NULL)
	{
		std::cout << "List has no data to print" << std::endl;
	}
	else if (_key<=-1)
	{
		//std::cout << "in data printer if"<<std::endl;
		dPrinter = start;
		do {
			std::cout<<"key: "<<dPrinter->key<<std::endl;
			dPrinter->d.displayData();
			std::cout << std::endl;
			dPrinter = dPrinter->next;
		} while(dPrinter != start);
	}
	else if (_key >= 0 && inList(_key))
	{
		dPrinter = start;
		for (;dPrinter->key != _key; dPrinter = dPrinter->next){}
		std::cout<<"key: "<<dPrinter->key<<std::endl;
		dPrinter->d.displayData();
		std::cout << std::endl;
	}
	else
	{
		std::cout << "\nkey not found in the list" << std::endl;
	}
	//std::cout << "in data printer end"<<std::endl;
}


inline CircularLinkedList::~CircularLinkedList()
{
	//std::cout << "in destructor calling make empty"<< std::endl;
	makeEmpty();
}
