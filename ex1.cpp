#include <iostream>
#include <cmath>

#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

#include "assignment.h"

#define MAXLENGTH 256

using namespace std;

//Function prototypes
void ex1_reverse_array();
void ex1_reverse_vector();
void ex1_reverse_stack();
void ex1_ordered_array();
void ex1_ordered_vector();
void ex1_ordered_queue();

//Main function
void ex1(){
	ex1_reverse_array();
}

void ex1_reverse_array() {
	string userinput;
	if(!(getline(cin, userinput))) {
		cin.clear(); cin.ignore(10000,'\n');
		cout << "Wrong input, try again.\n";
	}

	istringstream iss(userinput);
	char delim = ' ';
	string item;
	vector<string> words;
	while (getline(iss, item, delim)) {
			//From slide 331 VG101
			words.push_back(item);
	}

	for(unsigned long i = 0; i < words.size(); i++){
		cout << words[i];
	}

	//char* reversed = new char[strlen(userinput)]; //Works, but is not strictly using arrays as required
	//char reversed[strlen(userinput)]; //Forbidden by ISO C++ for some reason

	// char reversed[MAXLENGTH];
	// strcpy(reversed, userinput);
	// for(unsigned long i = 0; i < strlen(userinput)/2; i++){
	// 	reversed[i] = userinput[(strlen(userinput) - i - 1)];
	// 	reversed[strlen(userinput) - i - 1] = userinput[i];
	// }
	// cout << reversed << endl;

	//delete[] reversed;
}
