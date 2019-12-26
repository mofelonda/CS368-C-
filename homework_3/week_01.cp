// single line comment

/*
	block comment
*/

/*
	comment switch
	start with //* to switch this comment block off
// */

// # indicates a command for the compiler
// #include copies the entire contents of a file right here during compilation
// use <> for c++ library files
// use "" for files you write (.h) files
// iostream is where cin and cout are defined
#include <iostream>

// this line means that we can write "cout" instead of using the whole name "std::cout"
using namespace std;

// exactly one main function
// return type must be int
int main() {

	cout<<"Welcome to CS 368"<<endl;

	int pounds;
	cout << "Mike how much do you weigh? ";
	cin >> pounds;
	double conversion_factor = 0.454;
	cout << " you weigh " << conversion_factor * pounds << " kg" << endl;

	if (pounds < 1800) {
		for (int i = 0; i < 3; i++) {
			cout << "Wow you're in great shape!" << endl;
		}
	}
	else {
		int i = 0;
		while (i < 3) {
			i++;
			cout << "I love Mountain Dew too" << endl;
		}
	}

	return 0;
}

