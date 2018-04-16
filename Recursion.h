/******************************
* Henry McGee
* Lab2
* Instructor: Professor Goddard
* CPSC 2120
* Due: 02/6/2018
******************************/
#include <iostream>
#include <fstream>

using namespace std;

class Recursion {

	private:
	int array[10][10];

	public:
	Recursion(ifstream&);
	Recursion(const Recursion& obj);
	void print();
	void printGroupWith(int, int);		
};
