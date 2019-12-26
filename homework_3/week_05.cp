#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

void Type_Properties();
void Type_Sizes();

// define global variables outside of classes or functions
int global;

int main() {

	cout<<"  Primitive Types"<<endl;
	// int
	// float and double
	// char and wchar_t
	Type_Sizes();
	// Type_Properties();


	cout<<"\n  Literals"<<endl;
	int v1 = 20; // decimal
	int v2 = 06; // octal
	int v3 = 0x00a; // hex
	char c = 'a';
	wchar_t wc = L'a'; // wide characters
	long double ld = 1.2345L; // don't use the lower case 'l' it looks like a '1'
	unsigned long v4 = 12345UL;


	cout<<"\n  Initialization"<<endl;
	int v5 = 5;
	int v6(6); // same as line 36
	int v7 = {42}; // "list initialization" checks to make sure the number will fit in the variable
	// int v8 = {12345678908765432123456789098765432123456789}; // doesn't fit
	int v8{234}; // same as line 38

	cout<<"\n  Default Initialization"<<endl;
	// only global variables are default initialized - nothing else is


	cout<<"\n  Type Casting"<<endl; // happens automatically if possible
	bool b = 42;
	cout<<"b = "<<b<<endl;
	int v9 = b;
	cout<<"v9 = "<<v9<<endl;
	int pi = 3.14;
	cout<<"pi = "<<pi<<endl;
	double d = pi;
	cout<<"d = "<<d<<endl;
	cout<<setprecision(30)<<scientific;
	double d2 = 1.234567890123456789123456789012345678901234567890;
	cout<<"d2 = "<<d2<<endl;
	float f1 = d2;
	cout<<"f1 = "<<f1<<endl;
	cout<<fixed<<setprecision(5);

	int i = 42;
	unsigned u = 10;
	cout<<"unsigned - signed = "<<u-i<<endl;
	// infinite loop
//	for (unsigned i = 3; i>=0; i--)
//		cout<<i<<endl;

	// data loss
	cout<<"\n  Data loss"<<endl;
	//cout<<setprecision(30)<<scientific;
	i = 8;
	int j = 5;
	cout<<"8 / 5 = "<<i/j<<endl;
	double d3 = double(i) / (double) j; // two different forms of type casting
	cout <<"as doubles 8. / 5. = "<< d3 << endl;

	cout<<"\n  References / Aliases"<<endl;
	// & is the address of operator
	int var = 4;
	int ref = var;
	cout<<"var "<<var<<"   ref "<<ref<<endl;
	var++;
	cout<<"var "<<var<<"   ref "<<ref<<endl;
	ref++;
	cout<<"var "<<var<<"   ref "<<ref<<endl;
	int var2 = 3;
	ref = var2;
	cout<<"var "<<var<<"   ref "<<ref<<"  var2 "<<var2<<endl;

	// memory addresses
	// 0x01
	// 0x02
	// 0x03 4
	// 0x04 4
	// 0x05 3

	// symbol table - only used during compilation
	// var -> 0x003
	// ref -> 0x004
	// var2 ->0x005

	cout<<"\n  Pointers"<<endl;
	// a variable that holds the address of another variable
	int var3 = 5;
	int * ptr = &var3;
	cout<<"var3 "<<var3 << " ptr "<<ptr<<endl;
	cout<<"*ptr "<< *ptr<<endl;
	(*ptr)++;
	cout<<"var3 "<<var3 << " ptr "<<ptr<<endl;



	// 0x06 5 // var3
	// 0x07 0
	// 0x08 1
	// 0x09 2
	// 0x0A 3
	// 0x0B 4
	// 0x0C 0x08 arr_ptr


	cout<<"\n  Primitive Arrays - aka C style Arrays"<<endl;
	int arr[5];
	int arr2[5]= {0,1,2,3,4};
	cout<<"arr[2] = "<<arr2[2]<<endl;
	cout<<"arr[-5] = "<<arr2[-5]<<endl;
	cout<<"arr[24] = "<<arr2[24]<<endl;

	int *arr_ptr = arr2;
	cout<<"arr_ptr[2]"<<arr_ptr[2]<<endl;
	arr_ptr++;
	cout<<"arr_ptr[2] (after arr_ptr++) "<<arr_ptr[2]<<endl;


	return 0;
}




void Type_Sizes() {
	cout << "\n  Type Sizes" << endl;
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
	cout << "Size of long double : " << sizeof(long double) << " bytes" << endl;
	cout << "Size of char : " << sizeof(char) << " bytes" << endl;
	cout << "Size of char16_t : " << sizeof(char16_t) << " bytes" << endl;
	cout << "Size of char32_t : " << sizeof(char32_t) << " bytes" << endl;
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
