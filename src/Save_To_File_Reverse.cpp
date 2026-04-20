/*
 * Save_To_File_Reverse.cpp
 *
 *  Created on: Apr 20, 2026
 *      Author: jonathan Greene
 */

#include<iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

//pseudocode

// part 1
// create user_input string variable and assign it blank string
// ask user for input
// save input to file by appending to file at last read position

// part 2
// run reverse_input function passing in input
// read string and put in an array spliting based on space
// reverse the array
// loop through string and join back together
// save reverse_input to original file by appending last position after reading file

// Couldn't use the above method as C++ has no split or join methods
// opted to use the built in reverse in algorithms


using namespace std;

void reverse_input(){

	ifstream inFile("CSC450_CT5_mod5.txt");
	string content;

	if(inFile.is_open()){
		stringstream buffer;
		buffer << inFile.rdbuf();
		content = buffer.str();
		inFile.close();
	}

	// this used the reverse algorithm built in
	reverse(content.begin(), content.end());
	// this appends to the end of the file contents
	ofstream outFile("CSC450_CT5_mod5-reverse.txt", std::ios::trunc);
	if(outFile.is_open()){
		outFile << content;
		outFile.close();
		cout << "Succesfully reversed and appended to file" << endl;
	}
}

int main() {
	string user_input ="";
	cout << "Enter the input to be saved" << endl;
	// this gets the entire line of the input
	std::getline(std::cin, user_input);
	// checks to make sure the user didn't just press enter
	if(user_input.empty()){
		cout << "No input entered closing program";
		return 0;
	}
	// this appends to the end of the file contents
	std::ofstream outFile("CSC450_CT5_mod5.txt", std::ios::app);
	// checks if the file is open so we can write to it
	if(outFile.is_open()){
		outFile << user_input << "\n";
		outFile.close();
		cout << "Succesfully appended to file" << endl;
	}

	reverse_input();
	return 0;
}




