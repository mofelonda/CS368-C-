#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	cout << "Variable Declaration" << endl;
	int x; // note not default initialized
	cout << "  no default initialization: x " << x << endl;
	x = 5; // assignment
	cout << "  after assignment: x " << x << endl;
	int y = 5; // declaration and initialization
	cout << "  y " << y << endl;
	int a, b, c; // comma separated declaration list
	int d = 3, e = 6, f, g = 9; // may also include initialization
	cout << "  (a, b, c, d, e, f, g) = (" << a << ", " << b << ", " << c << ", "
			<< d << ", " << e << ", " << f << ", " << g << ")" << endl;

	// boolean statements
	cout << "Boolean Statements" << endl;
	bool condition = true;
	cout << "condition ";
	if (condition)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "0 ";
	if (0)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "1 ";
	if (1)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "2 ";
	if (2)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "-45 ";
	if (-45)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "true ";
	if (true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "false ";
	if (false)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "a ";
	if ('a')
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "3<7 ";
	if (3 < 7)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "3!=6 ";
	if (3 != 6)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "4==4 ";
	if (4 == 4)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "true || false ";
	if (true || false)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "true && true ";
	if (true && true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	d = 5;
	cout << "assignment d=0 ";
	if ((d = 0))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "d " << d << endl;

	cout << "Increment" << endl;
	int i = 0;
	cout << setw(8) << left << "i=0 : " << i << endl;
	i++;
	cout << setw(8) << left << "i++ : " << i << endl;
	i--;
	cout << setw(8) << left << "i-- : " << i << endl;
	i = i + 1;
	cout << setw(8) << left << "i=i+1 : " << i << endl;
	i += 1;
	cout << setw(8) << left << "i+=1 : " << i << endl;
	i *= 2;
	cout << setw(8) << left << "i*=2 : " << i << endl;

	cout << "Pre and Post increment operators" << endl;
	cout << setw(8) << left << "++i : " << ++i << endl;
	cout << setw(8) << left << "i : " << i << endl;
	cout << setw(8) << left << "i++ : " << i++ << endl;
	cout << setw(8) << left << "i : " << i << endl;

	//	for (initialization; boolean condition; increment) {
	//		 body
	//		 note: only one initialization statement - may be comma separated list of multiple variables
	//		 note: increment may be a comma separated list of multiple statements
	//		 note: initialization, boolean condition, and increment are all optional
	//	}

	cout << endl << "Countdown" << endl;
	for (int i = 6; i >= 0; i--) {
		cout << "  " << i << endl;
	}
	cout << "Blast Off!!!" << endl << endl;

	// more complicated example with multiple declarations and increment statements
	cout << setw(3) << right << "n" << setw(6) << "n^2" << endl;
	for (int i = 0, square = 0; i < 10; i++, square = i * i) {
		cout << setw(3) << i << setw(4) << square << endl;
	}

	return 0;
}
