#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	string name;

	// squares of numbers
	cout << setw(3) << right << "n" << setw(5) << "n^2" << endl;
	for (int i = 0, square = 0; i < 10 || square > 100; i++, square = i * i) {
		cout << setw(3) << i << setw(4) << square << endl;
	}

	// continue
	// break
	// label and goto
	// Countdown
	cout << endl << "Countdown" << endl;
	for (int i = 8; i >= 0; i--) {
		if (i==6) continue;
		// if (i==4) break;
		if (i == 3) goto ABORT;
		cout << "  " << i << endl;
	}
	cout << "Blast Off!!!" << endl << endl;

	ABORT:
	cout<<"Launch aborted!"<<endl;

	// streams - see PowerPoint

	//* comment switch - change to /* to comment out the block of code below that requires input from user

	// cin
	int x;
	cout<<"enter an integer: ";
	cin>>x;
	cout<<" you entered "<<x<<endl;

	// chaining
	int y, z;
	cout<<"enter 3 integers: ";
	cin >> x >> y >> z;
	cout<<" you entered "<<x<<" "<<y<<" and "<< z<<endl;

	// getline (source stream (cin or file, variable name)
	cout<<"enter your name: ";
	cin>> name;
	getline(cin, name);
	cout<<"your name is "<<name<<endl;


	// read an unknown number of inputs
	// eol stands for end of line and is either ctrl-z (windows) or ctrl-d (mac/linux)
	int sum=0;
	cout<<"enter some numbers. eol to end ";
	while ( cin >> x) {
		sum += x;
	}
	cout<<"the sum is "<<sum<<endl;

	// */

	cout<<endl<<"Intro to strings"<<endl;

	// intro to strings
	// +, ==, length, []
	string first_name = "Inigo";
	string last_name = "Montoya";
	name = first_name + " " + last_name;
	cout<<"Hello my name is "<<name<<". You killed my father.  Prepare to die."<<endl;
	cout<<"first_name == last_name: ";
	if (first_name == last_name) cout<<"true"<<endl; else cout<<"false"<<endl;
	int length = name.length();
	cout<<"My name has "<<length<<" characters"<<endl;
	name[2] = 'a';
	cout<<"name[2] = a: Hello my name is "<<name<<". You killed my father.  Prepare to die"<<endl;


	cout<<endl<<"IO manipulators"<<endl;
	// IO manipulators
	name = "Inigo Montoya"; // correct the spelling

	// flush - forces print immediately instead of waiting for operating system
	// newline character \n does not force the buffer to be written
	cout<<"flush: "<<"Hello. My name is "<<name<<". You killed my father...\n"<<flush;

	// endl - add a newline and flush the buffer
	cout<<"endl: "<<"Hello. My name is "<<name<<". You killed my father..."<<endl;

	// setw - reserve some space for the next variable or text - great for table formatting
	cout<<"setw: "<<"Hello. My name is "<<setw(25)<<name<<". You killed my father..."<<endl;

	// setfill - pad the reserved space from setw with a different character, default is space
	cout<<"setfill: "<<"Hello. My name is "<<setfill('*')<<setw(25)<<name<<". You killed my father..."<<endl;

	// left - left justify the text added to a setw box
	// right - yup
	cout<<"left: "<<"Hello. My name is "<<left<<setw(25)<<name<<". You killed my father..."<<endl;

	// boolalpha and noboolalpha
	cout<<endl;
	bool tf = true;
	cout<<"default boolean: "<<"tf = "<<tf<<endl;
	cout<<"boolalpha: "<<boolalpha<<"tf = "<<tf<<endl;
	cout<<"note - retains state: "<<"tf = "<<tf<<endl;
	cout<<"noboolalpha: "<<noboolalpha<<"tf = "<<tf<<endl;

	cout<<endl;
	double d = 12.0;
	cout<<"default double: "<<"d = "<<d<<endl;
	cout<<"showpoint: "<<showpoint<<"d = "<<d<<endl;
	cout<<noshowpoint;
	d = 0.0000123456789;
	cout<<"default double: "<<"d = "<<d<<endl;
	cout<<"setprecision: "<<setprecision(4)<<"d = "<<d<<endl;
	cout<<"showpos: "<<showpos<<"d = "<<d<<endl;
	cout<<"note - retains state: "<<"d = "<<d<<endl;
	cout<<"noshowpos: "<<noshowpos<<"d = "<<d<<endl;
	cout<<"scientific: "<<scientific<<"d = "<<d<<endl;
	cout<<"uppercase: "<<uppercase<<"d = "<<d<<endl;
	cout<<"nouppercase: "<<nouppercase<<"d = "<<d<<endl;
	cout<<"fixed: "<<fixed<<"d = "<<d<<endl;

	cout<<endl;
	int i = 31;
	cout<<"default integer: "<<"i = "<<i<<endl;
	cout<<"hex: "<<hex<<"i = "<<i<<endl;
	cout<<"uppercase: "<<uppercase<<"i = "<<i<<endl;
	cout<<"oct: "<<oct<<"i = "<<i<<endl;
	cout<<"dec: "<<dec<<"i = "<<i<<endl;

	// skipws - skip leading whitespace with cin
	// noskipws - keep leading whitespace with cin
	// test this at home

	return 0;
}
