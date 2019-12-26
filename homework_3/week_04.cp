#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

void Type_Properties();
void Type_Sizes();

// definition - uses {} and includes the function body
int Feet_To_Inches(int feet) {
	return feet * 12;
}
// declarations - no {function body} just ends in ; function is defined below
int Feet_To_Inches(int feet, int inches);
void Feet_To_Inches_By_Reference(int feet, int &inches);
int Feet_To_Inches_With_Default_Inches(int feet, int inches = 0);

int main() {

	// STRINGS

	// 0123456789
	// ab234cdefgh
	string text = "abcd";
	cout << text << endl;
	cout << boolalpha << "empty " << text.empty() << endl;
	cout << "[ ] " << text[3] << endl;
	text.append("efg");
	cout << "append " << text << endl;
	text.push_back('h');
	cout << "push_back " << text << endl;
	text.insert(2, "234");
	cout << "insert " << text << endl;
	string sub = text.substr(2, 4);
	cout << "substring " << sub << endl;
	cout << "compare " << text.compare(sub) << endl;
	cout << "compare " << sub.compare(text) << endl;
	cout << "find " << text.find("efg") << endl;
	cout << "find " << text.find("z") << endl;
	cout << "string::npos = " << string::npos << endl; // npos is returned if the text is not found

	cout << "\nWriting and Reading From Files" << endl;
	// create an output file stream object and attach it to a file
	ofstream out;
	out.open("afile.txt");
	// write some text to the file - this works just like cout
	out << "   some    text   " << endl;
	// close the file when finished
	out.close();

	// create an input file stream object and attach it to a file
	ifstream in;
	in.open("afile.txt");
	// read in some text
	string text1, text2;
	in >> text1 >> text2;
	cout << endl << text1 << " " << text2 << " done" << endl;
	// close the file when finished
	in.close();

	cout << "\nIntro to Functions" << endl;
	int feet1 = 6;
	int height1 = Feet_To_Inches(feet1);
	cout << "You are " << height1 << " inches tall" << endl;

	cout << "\nOverloading Functions" << endl;
	int feet2 = 6;
	int inches2 = 1;
	int height2 = Feet_To_Inches(feet2, inches2);
	cout << "You are " << height2 << " inches tall" << endl;
	cout << "You are " << feet2 << " feet and " << inches2 << " inches tall"
			<< endl;
//
//
	cout << "\nCall by Reference" << endl;
	int feet3 = 6;
	int inches3 = 1;
	Feet_To_Inches_By_Reference(feet3, inches3);
	cout << "You are " << inches3 << " inches tall" << endl;

	cout << "Default Values" << endl;
	int feet4 = 6;
	int inches4 = 1;
	int height4 = Feet_To_Inches_With_Default_Inches(feet4, inches4);
	cout << "You are " << height4 << " inches tall" << endl;
	int height5 = Feet_To_Inches_With_Default_Inches(feet4);
	cout << "You are " << height5 << " inches tall with default" << endl;

	cout << "Primitives " << endl;
	Type_Sizes();
	Type_Properties();

	return 0;
}

/* declaring and defining functions
 return_type function_name(parameter_type parameter_name) {
 function_body
 return variable_name
 }
 */

// definitions
int Feet_To_Inches(int feet, int inches) {
	inches = feet * 12 + inches;
	return inches;
}

void Feet_To_Inches_By_Reference(int feet, int &inches) {
	inches = feet * 12 + inches;
}

int Feet_To_Inches_With_Default_Inches(int feet, int inches) {
	inches = feet * 12 + inches;
	return inches;
}

void Type_Sizes() {
	cout << "\nTYPE SIZES" << endl;
	cout << "Size of char : " << sizeof(char) << " byte" << endl;
	cout << "Size of int : " << sizeof(int) << " bytes" << endl;
	cout << "Size of short int : " << sizeof(short int) << " bytes" << endl;
	cout << "Size of long int : " << sizeof(long int) << " bytes" << endl;
	cout << "Size of long long int : " << sizeof(long long int) << " bytes"
			<< endl;
	cout << "Size of size_t : " << sizeof(size_t) << " bytes" << endl;
	cout << "Size of signed long int : " << sizeof(signed long int) << " bytes"
			<< endl;
	cout << "Size of unsigned long int : " << sizeof(unsigned long int)
			<< " bytes" << endl;
	cout << "Size of float : " << sizeof(float) << " bytes" << endl;
	cout << "Size of double : " << sizeof(double) << " bytes" << endl;
	cout << "Size of wchar_t : " << sizeof(wchar_t) << " bytes" << endl;
}

void Type_Properties() {
	cout << "\nTYPE PROPERTIES" << endl;

	// typedef lets us assign a new name for a type
	string type = "float";
	typedef float T;

	std::cout << std::boolalpha;
	std::cout << "Minimum value for " << type << " "
			<< std::numeric_limits<T>::min() << '\n';
	std::cout << "Maximum value for " << type << " "
			<< std::numeric_limits<T>::max() << '\n';
	std::cout << type << " is signed: " << std::numeric_limits<T>::is_signed
			<< '\n';
	std::cout << "Non-sign bits in " << type << " "
			<< std::numeric_limits<T>::digits << '\n';
	std::cout << type << " has infinity: "
			<< std::numeric_limits<T>::has_infinity << '\n';
}
