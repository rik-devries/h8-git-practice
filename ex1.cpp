#include <iostream>
#include <cmath>

#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <stack>
#include <queue>

#include "assignment.h"

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

}

void ex1_ordered_queue(){
	string userinput;
	if(!(getline(cin, userinput))) {
		cin.clear(); cin.ignore(10000,'\n');
		cout << "Wrong input, try again.\n";
	}

	queue<string> words;
	string item;
	char delim = ' ';
	istringstream iss(userinput);
	while (getline(iss, item, delim)) {
		words.push(item);
	}
	while(!words.empty()){
		cout << words.front() << " ";
		words.pop();
	}
}

void ex1_ordered_vector(){
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
		cout << words[i] << " ";
	}
}

void ex1_ordered_array(){
	string userinput;
	if(!(getline(cin, userinput))) {
		cin.clear(); cin.ignore(10000,'\n');
		cout << "Wrong input, try again.\n";
	}
	//Count words in line
	istringstream iss(userinput);
	char delim = ' ';
	string item;
	int counter = 0;
	while (getline(iss, item, delim)) {
		counter++;
	}
	//Now create an array large enough to hold all the words and write them
	string* words = new string[counter];
	int filled = 0;
	istringstream iss2(userinput);
	while (getline(iss2, item, delim)) {
		words[filled] = item;
		filled++;
	}
	for(int i = 0; i < counter; i++){
		cout << words[i] << " ";
	}
	delete[] words;
}

void ex1_reverse_stack(){
	string userinput;
	if(!(getline(cin, userinput))) {
		cin.clear(); cin.ignore(10000,'\n');
		cout << "Wrong input, try again.\n";
	}
	//Write all the words to a stack
	stack<string> words;
	string item;
	char delim = ' ';
	istringstream iss(userinput);
	while (getline(iss, item, delim)) {
		words.push(item);
	}
	while(!words.empty()){
		cout << words.top() << " ";
		words.pop();
	}
}

void ex1_reverse_array() {
	string userinput;
	if(!(getline(cin, userinput))) {
		cin.clear(); cin.ignore(10000,'\n');
		cout << "Wrong input, try again.\n";
	}
	//Count words in line
	istringstream iss(userinput);
	char delim = ' ';
	string item;
	int counter = 0;
	while (getline(iss, item, delim)) {
		counter++;
	}
	//Now create an array large enough to hold all the words and write them
	string* words = new string[counter];
	int filled = 0;
	istringstream iss2(userinput);
	while (getline(iss2, item, delim)) {
		words[filled] = item;
		filled++;
	}
	//Now reverse all the words in a new array
	string* reversed = new string[counter];
	for(int i = counter-1; i >= 0; i--){
		reversed[(counter-1)-i] = words[i];
	}
	for(int i = 0; i < counter; i++){
		cout << reversed[i] << " ";
	}
	delete[] words;
	delete[] reversed;
}

void ex1_reverse_vector() {
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
	reverse(words.begin(), words.end());
	for(unsigned long i = 0; i < words.size(); i++){
		cout << words[i] << " ";
	}
}
