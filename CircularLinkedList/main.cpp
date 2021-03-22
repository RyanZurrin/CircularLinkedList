#include "CircularLinkedList.h"


int main()
{
	CircularLinkedList test;
	Data rz("Ryan Zurrin", "7/22/1981", 55.55);
	Data gp("Greg Panczner", "1/20/1955", 22.78);
	Data bp("Beverly Provost", "12/29/1965", -78.88);
	Data zr("Ryan Zurrin", "7/22/1981", 55.55);
	Data pg("Greg Panczner", "1/20/1955", 22.78);
	Data pb("Beverly Provost", "12/29/1965", -78.88);
	Data removed;

	test.addItem(3, rz);
	test.addItem(2, bp);
	std::cout << "isFull: " << test.isFull()<< std::endl;
	test.addItem(9, gp);
	test.addItem(6, zr);
	std::cout<< "\nqty: " << test.getQty();
	test.displayKeys();
	test.addItem(4, pg);
	test.addItem(5, pb);
	test.addItem(2, rz);
	test.addItem(7, bp);
	std::cout<< "\nqty: " << test.getQty();
	test.displayKeys();
	test.addItem(6, gp);
	test.addItem(8, zr);
	test.addItem(11, pg);
	test.addItem(10, pb);
	test.displayKeys();
	test.getItem(2, removed);
	removed.displayData();
	test.getItem(3, removed);
	removed.displayData();
	test.getItem(7, removed);
	removed.displayData();
	test.getItem(11, removed);
	removed.displayData();
	test.displayKeys();
	test.deleteItem(2, removed);
	removed.displayData();
	test.displayKeys();
	test.deleteItem(6, removed);
	removed.displayData();
	test.displayKeys();
	test.displayData(6);

	return 0;
}
/*
 *
 */
