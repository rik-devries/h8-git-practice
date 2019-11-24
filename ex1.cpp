#include <iostream>
#include <cmath>
#include <cstring>

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
	char userinput[MAXLENGTH];
	if(!(cin >> userinput)) {
		cin.clear(); cin.ignore(10000,'\n');
		cout << "Wrong input, try again.\n";
	}

	//char* reversed = new char[strlen(userinput)]; //Works, but is not strictly using arrays as required
	//char reversed[strlen(userinput)]; //Forbidden by ISO C++ for some reason
	char reversed[MAXLENGTH];
	strcpy(reversed, userinput);
	for(unsigned long i = 0; i < strlen(userinput)/2; i++){
		reversed[i] = userinput[(strlen(userinput) - i - 1)];
		reversed[strlen(userinput) - i - 1] = userinput[i];
	}
	cout << reversed << endl;
	//delete[] reversed;
}