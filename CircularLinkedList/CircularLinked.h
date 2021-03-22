#pragma once
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include "Node.h"

/**
 * \brief circular linked list with no duplicates and sorted upon each
 * insertion of an element to the list. Instances of list can be made using the
 * default constructor with a max size of 200 and a overloaded constructor
 * taking one int which is the size max size of the list.
 */
class CircularLinkedList
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="CircularLinkedList"/> class.
	/// </summary>
	CircularLinkedList();

	/// <summary>
	/// Initializes a new instance of the <see cref="CircularLinkedList"/> class.
	/// </summary>
	/// <param name="maxSize">The maximum size the list can grow to.</param>
	CircularLinkedList(int maxSize);

	/// <summary>
	/// Adds the data and key to the list
	/// </summary>
	/// <param name="val">The key value of data.</param>
	/// <param name="_d">The data to be added.</param>
	/// <returns></returns>
	bool addItem(int val, Data _d);

	/// <summary>
	/// Deletes the list node the key matching the value passed in.
	/// </summary>
	/// <param name="val">The key value to be deleted.</param>
	/// <param name="_d">The reference to save the deleted data too
	/// which allows for verification that the right thing was deleted.</param>
	/// <returns>true if key value and data to be deleted was found :
	/// else false</returns>
	bool deleteItem(int val, Data& _d);

	/// <summary>
	/// Gets the data from list that matches the key value of the argument.
	/// </summary>
	/// <param name="val">The key value to be searched for.</param>
	/// <param name="_d">The reference to a data member to save the results
	/// of the search to.</param>
	/// <returns>true if the data was found : else false</returns>
	bool getItem(int val, Data& _d);

	/// <summary>
	/// Finds the item.
	/// </summary>
	/// <param name="val">The value.</param>
	/// <returns></returns>
	bool inList(int val);

	/// <summary>
	/// Gets the qty.
	/// </summary>
	/// <returns>returns the size of the list as an integer</returns>
	int getQty()const;

	/// <summary>
	/// Determines whether this instance is full.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is full; otherwise, <c>false</c>.
	/// </returns>
	bool isFull()const;

	/// <summary>
	/// Determines whether this instance is empty.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is empty; otherwise, <c>false</c>.
	/// </returns>
	bool isEmpty()const;

	/// <summary>
	/// Makes the list empty by deleting all list nodes and setting the
	/// start and curr pointers to NULL.
	/// </summary>
	/// <returns>true if able to delete nodes : else false</returns>
	bool makeEmpty();

	/// <summary>
	/// Displays this instance of each key in the list.
	/// </summary>
	void displayKeys()const;

	/// <summary>
	/// Displays the data.
	/// </summary>
	/// <param name="_key">The key.</param>
	void displayData(const int _key);

	/// <summary>
	/// Finalizes an instance of the <see cref="CircularLinkedList"/> class.
	/// </summary>
	~CircularLinkedList();

private:
	int qty;
	int max;
	Node* start;
	Node* curr;

};

#endif
