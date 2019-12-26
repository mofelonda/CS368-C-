#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// multidimensional arrays require all but the first dimension's size
//void Print_5x5_Matrix(int (*m)[5]) {
//void Print_5x5_Matrix(int m[][5]) {
void Print_5x5_Matrix(int m[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << setw(4) << m[i][j];
		}
		cout << endl;
	}
}

// double Compute_Average(int a[5], const int size) {
// double Compute_Average(int a[], const int size) {
double Compute_Average(int *a, const int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i];
	return sum / size;
}

int main() {

	// Pointer Review
	cout << "\n  Pointer Review" << endl;
	int v = 5;
	int *v_ptr = nullptr, *i = &v; // each pointer requires a *
	cout << "v = " << v << " i = " << i << " *i= " << *i << endl;
	v++;
	cout << "v = " << v << " i = " << i << " *i= " << *i << endl;

	// Constant Pointers
	cout << "\n  Constant Pointers" << endl;
	const int *ptr2 = &v; // can't change value
	// *ptr2 += 1; // error
	cout << "v = " << v << " i = " << i << " *i= " << *i << endl;
	v++;
	cout << "v = " << v << " i = " << i << " *ptr2= " << *ptr2 << endl;
	int x = 0;
	ptr2 = &x;
	cout << "v = " << v << " i = " << i << " *ptr2= " << *ptr2 << endl;
	int *const ptr3 = &v; // can't change address
	cout << "v = " << v << " i = " << i << " *ptr3= " << *ptr3 << endl;
	*ptr3 = 11;
	cout << "v = " << v << " i = " << i << " *ptr3= " << *ptr3 << endl;
	// ptr3 = &i; // error

	cout << "\n  Primitive Array Review" << endl;
	int arr1[5];
	arr1[0] = 2;
	arr1[1] = 3;
	arr1[2] = 3;
	arr1[3] = 3;
	arr1[4] = 3;
	int arr2[5] = { 0, 1, 2, 3, 4 };
	for (int i = 0; i < 5; i++)
		cout << setw(4) << arr1[i];
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << setw(4) << arr2[i];
	cout << endl;
	const int size = 5;
	int arr3[size]; // C++ is supposed to require constant size array dimensions - not all compilers catch this one
	arr3[0] = 2;
	for (int i = 0; i < 5; i++)
		cout << setw(4) << arr3[i];
	cout << endl;

	// array declaration is the same as creating a constant pointer
	//  with reserving memory for the rest of the array
	// just like the line below
	// int * const arr3;

	// pointer arithmetic
	cout << "\n  Pointer Arithmetic" << endl;
	int *arr_ptr = arr2;
	cout << "*arr_ptr[0] " << arr_ptr[0] << endl;
	arr_ptr += 2;
	cout << "*arr_ptr[0] " << arr_ptr[0] << endl;

	// Character Arrays - require '\0'
	cout << "\n  Character Arrays" << endl;
	char lang1[] = { 'a', 'b', 'c', '\0' };
	cout << lang1 << endl;
	char lang2[] = { 'C', '+', '+' };
	cout << lang2 << endl;
	// C++abc\0
	char lang3[] = "C++";
	cout << lang3 << endl;
	//char lang4[3] = "C++"; // error
	//cout<<lang4<<endl;

//	cout<<"\n  No Copy / Assignment / Relational Operations with Primitive Arrays"<<endl;
	int arr5[] = { 1, 2, 3 };
	int arr6[3];
	//arr6 = arr5; //  error - no assignment
	//int arr7[3] = arr5; // error - no copy constructor
	int arr8[] = { 1, 2, 3 };
	if (arr5 == arr8) // compares location in memory not values
		cout << "same" << endl;
	else
		cout << "different" << endl;
	int *int_ptr = arr5;
	if (arr5 == int_ptr)
		cout << "same" << endl;
	else
		cout << "different" << endl;

	// Multidimensional Arrays
	cout << "\n  Multidimensional Arrays" << endl;
	int m[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			m[i][j] = i * j;
	Print_5x5_Matrix(m);

	// Passing Arrays to Functions - three methods
	cout << "\n  Passing Arrays To Functions" << endl;
	int arr9[] = { 1, 2, 3, 4, 5 };
	cout << "average = " << Compute_Average(arr9, 5) << endl;

	// New and Delete
	cout << "\n  New and Delete" << endl;
	// allocates memory on the heap and returns a pointer to it
	string *s = new string("hello");
	cout << *s << endl;
	*s += " world";
	cout << *s << endl;
	// delete s;
	// cout<<*s<<endl; // stale pointer - error - might compile but with unpredictable behavior

	string *t = s;
	cout << *t << endl;
	delete s;
	//cout<<*t<<endl; // also a stale pointer - error - might compile but with unpredictable behavior
	delete t; // double free - error might release memory used by other variables = unpredictable behavior


	cout << "\n  Reference review" << endl;
	// think of references as easy pointers
	int v11 = 4;
	int &r = v11;
	cout << "v11 " << v11 << "  r " << r << endl;
	v11++;
	cout << "v11 " << v11 << "  r " << r << endl;
	r++;
	cout << "v11 " << v11 << "  r " << r << endl;

}
