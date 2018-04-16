/******************************
* Henry McGee
* Lab2
* Instructor: Professor Goddard
* CPSC 2120
* Due: 02/6/2018
******************************/
#include <string>
#include <fstream>
#include <iostream>
#include "Recursion.h"

using namespace std;

Recursion::Recursion(ifstream& ifr) { 	
	int i = 0;
	int j = 0;
	string temp;

	for(i = 0; i < 10; i++) {
		getline(ifr, temp);
		for(j = 0; j < 10; j++) {
			
			if(temp[j] == '.') {
				array[i][j] = 0; 
			}
			
			else
				array[i][j] = 1;
		}
	}	
}

Recursion::Recursion(const Recursion& obj) {
	int i = 0;
	int j = 0;

	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			array[i][j] = obj.array[i][j];
		}
	}
}

void Recursion::print() {
	int i = 0;
	int j = 0;
	int groupNumber = 1;
	int arrayCopy[10][10];

	for( i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			arrayCopy[i][j] = array[i][j];
		}
	}

	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			if(array[i][j] == 1) {
				cout << "Group " << groupNumber << ":  "; 				
				cout << " (" << i << ", " << j << ")";
				array[i][j] = 0;
				printGroupWith(i, j);
								
				cout << endl;
				groupNumber++;
			}		
		}
	}
}

void Recursion::printGroupWith(int row, int col) {
	int i = row;
	int j = col;
	
	if((array[i][j + 1] == 1) && (j < 10)) {
		cout << " (" << i << ", " << j + 1 << ")";
		array[i][j + 1] = 0;		
		printGroupWith(i, j + 1);
	}
			
	if((array[i][j - 1] == 1) && (j > 0)) {
		cout << " (" << i << ", " << j - 1 << ")";	
		array[i][j - 1] = 0;
		printGroupWith(i, j - 1);
	}

	if((array[i + 1][j] == 1) && (i < 10)) {
		cout << " (" << i + 1 << ", " << j << ")";	
		array[i + 1][j] = 0;
		printGroupWith(i + 1, j);
	}

	if((array[i - 1][j] == 1) && (i > 0)) {
		cout << " (" << i - 1 << ", " << j << ")";	
		array[i - 1][j] = 0;
		printGroupWith(i - 1, j);
	}
}

int main(int argc, char const *argv[]) {
	ifstream ifr(argv[1]);
	Recursion temp(ifr);
	temp.print();

	return 0;
}
