#include "assignment.h"

void ex1(){
    //Write code for exercise 1
	
}

void read_input(string* output){
	string userinput;
	if(!(cin >> userinput)) {
		cin.clear(); cin.ignore(10000,'\n');
		cout << "Wrong input, try again.\n";
	}
	*output = userinput;
}

void ex1_reverse_array() {
	string* regular = new string;
	read_input(regular);
	
	
	delete regular;
}