#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// http://www.cplusplus.com/reference/stl/
	// http://www.cplusplus.com/reference/vector/vector/

	cout << "\n## vector" << endl;

	cout << "\n## initialization" << endl;
	vector<string> names;
	cout<<"size "<<names.size()<<endl;

	cout<<"\n## adding elements"<<endl;
	names.push_back("Michael");
	names.push_back("Freddy");
	names.push_back("Chucky");
	cout<<"size "<<names.size()<<endl;

	cout<<"\n## for loop"<<endl;
	for (int i=0;i<names.size();i++)
		cout<<"names["<<i<<"] "<<names[i]<<endl;

	cout<<"\n## range for loop"<<endl;
	for (string s : names)
		cout<<s<<endl;

	cout<<"\n## auto compiler will automatically determines the type if possible"<<endl;
	int asdf[] {12,2,3,5};
	for (auto e : asdf)
		cout<<e<<endl;
	vector<string> names2{"Ursula", "Hannibal", "Ghost Face", "Casper"};
	for (auto s : names2)
		cout<<s<<endl;


	cout<<"\n## common initialization errors 1"<<endl;
	//vector<string> names3("Pinhead", "Norman", "Jigsaw"); // use {} not () for list initialization
	cout<<"\n## common initialization errors 2"<<endl;
	// vector<string> names4(); // C++ thinks this is a function declaration
	// names4.push_back("Sweeny Todd"); // but doesn't generate an error until here

	cout<<"\n## vector constructor"<<endl;
	//	vector<type> variable_name(size, [default_value=0]);
	vector<int> numbers(4); // how many
	for (auto e : numbers) {cout<<setw(4)<<e;} cout<<endl;
	vector<int> numbers2(4, -2);
	for (auto e : numbers2) {cout<<setw(4)<<e;} cout<<endl;

	cout << "\n## copy constructor" << endl;
	vector<string> names5(names);
	for (string s : names5)
		cout<<s<<endl;

	cout << "\n## verifying copy and not reference" << endl;
	names[1] = "Imhotep";
	for (string s : names)
		cout<<s<<endl;
	cout<<endl;
	for (string s : names5)
		cout<<s<<endl;

	cout<<"\n## assignment"<<endl;
	vector<string> names6;
	names6=names;
	cout << "\n## verifying copy and not reference" << endl;
	names[1] = "Freddy";
	for (string s : names)
		cout<<s<<endl;
	cout<<endl;
	for (string s : names6)
		cout<<s<<endl;


	cout << "\n## reference" << endl;
	vector<string> &names7 = names;
	names[1] = "Frankenstein";
	for (string s : names)
		cout<<s<<endl;
	cout<<endl;
	for (string s : names7)
		cout<<s<<endl;


	cout<<"\n## == "<<endl;
	names[1] = "Freddy"; // change back so they have identical entries - comment this to verify they are different
	for (string s : names)
		cout<<s<<endl;
	cout<<endl;
	for (string s : names5)
		cout<<s<<endl;
	if (names == names5) cout<<"names == names5"<<endl; else cout<<"names != names 5"<<endl;


	cout << "\n## element access - [] front() back() at()" << endl;
	cout<<names.front()<<endl;
	cout<<names.back()<<endl;
	cout<<names.at(0)<<endl; // checks range = safer
	names.front() = "Pennywise"; // this function call returns a reference to the first element of the vector so we can use it in an assignment statement
	cout<<names[0]<<endl;

	cout << "\n## iterators - begin() end() - these are much like pointers" << endl;
	cout<<*names.begin()<<endl;
	vector<string>::iterator name_iterator = names.begin();
	cout << "\n## iterator access  " <<endl;
	auto it = names.begin(); // I can never remember vector<string>::iterator so I just use auto for all iterators
	cout<<*it<<endl;
	it++; // pointer arithmetic
	cout<<*it<<endl;

	// names.end() - points to the first entry after the end of the vector so use < with it in loops
	for (auto iter = names.begin(); iter<names.end(); iter++)
		cout<<"*iter "<<*iter<<endl;

	cout << "\n## sort "<<endl;
	sort(names.begin(), names.end());
	for (auto iter = names.begin(); iter<names.end(); iter++)
		cout<<"sorted "<<*iter<<endl;


	cout << "\n## insert" << endl;
	names.insert(names.begin() + 2, names2.begin(), names2.end());
	for (auto iter = names.begin(); iter<names.end(); iter++) {
		cout<<*iter<<endl;
	}

}
