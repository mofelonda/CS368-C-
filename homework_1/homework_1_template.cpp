/* *******************************************************
 * Name: Mo Felonda
 * Wisc ID: 9073207327
 * OS: macOS
 * IDE / text editor: CLion
 * Compiler: CMake
 * How long did the assignment take you to complete in minutes: 20 minutes
 * What other resources did you consult (copy and paste links below: N/A
*/ // ****************************************************

// Include appropriate libraries to work with input/output and strings.
#include <string>
#include <iostream>


using namespace std;

// function declarations -- do not changes these
// you must complete the function definitions below
string Get_Name();
void Print_Welcome_Message(string name);

// do not change main
int main() {
	string name;
	name = Get_Name();
	Print_Welcome_Message(name);
}


// Get_Name asks the user to enter their name
// Note: "Blackbeard", "Anne Bonny", and
// "Captain Jack Sparrow" are all valid names
// The user may also choose not to enter a name.
// input: none
// output: a string containing the user entered name
// Note: do not change the function prototype on the next line
string Get_Name() {
	// declare a variable to hold the name
	string name = "Mike";

	// prompt the user to enter a name
    cout << "Enter your name: ";

	// read the name entered by the user
    getline(cin, name);

	// return the name entered by the user
	    // i.e. replace the text "name" in the return
	    // statement below with the name supplied by the user
	return name;
}

// Prints the welcome message
// input: a string with the user's name
// output: writes the welcome message to the screen
// return value: none
void Print_Welcome_Message(string name) {
    int i;
    int nameLength = name.length();
    if (name == "") {
        nameLength--;
    }

    // print the top row of stars
    cout << endl << "***********************************";
    for (i = 0; i <= nameLength; i++) {
        cout << "*";
    }
    cout << endl;

	// print the second line
    cout << "*                                 ";
    for (i = 0; i <= nameLength; i++) {
        cout << " ";
    }
    cout << "*" << endl;

	// print the welcome message
	if (name == "") {
        cout << "* Hello! Welcome to CS 368 (C++)! *" << endl;
	}
	else {
        cout << "* Hello " << name << "! Welcome to CS 368 (C++)! *" << endl;
	}

	// print the fourth line
    cout << "*                                 ";
    for (i = 0; i <= nameLength; i++) {
        cout << " ";
    }
    cout << "*" << endl;

	// print the bottom row of stars
    cout << "***********************************";
    for (i = 0; i <= nameLength; i++) {
        cout << "*";
    }
    cout << endl;

	return;
}


/* Sample console text - the console should appear exactly as follows
Including white spaces
I use an automatic grading script to easily identify correct work.


Enter your name: Mike

****************************************
*                                      *
* Hello Mike! Welcome to CS 368 (C++)! *
*                                      *
****************************************


Enter your name: The Dread Pirate Roberts

************************************************************
*                                                          *
* Hello The Dread Pirate Roberts! Welcome to CS 368 (C++)! *
*                                                          *
************************************************************


(If the user doesn't enter a name)
Enter your name:

***********************************
*                                 *
* Hello! Welcome to CS 368 (C++)! *
*                                 *
***********************************


*/

