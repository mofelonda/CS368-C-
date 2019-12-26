/* ******************************************************
 * Name: Mo Felonda
 * Wisc ID: felonda, 9073207327
 * OS: macOS Catalina
 * IDE (or text editor): CLion
 * Compiler: CMake
 * How long did the assignment take you to complete in minutes: 120
 * What other resources did you consult (copy and paste links below):
 * N/A
 * ******************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int counter;

// input: none
// output: a number entered by the user
// alternative output: if the three lines that get input from the user are commmented out
// then the the function will return the next number in the sequence provided in the vector
// test_your_code_with_these_numbers. Use these numbers to duplicate the sample output
// provided in the assignment description to test your code
int Get_User_Input() {
	//* Comment the three lines in this block to test your code with the input below
	int n;
	cin >> n;
	return n;
	// */

	vector<int> test_your_code_with_these_numbers { 1, 28, 13, 43, -1, // Input_Numbers
			7,					// Print_Numbers
			2, 1, -1, 			// Safe_Insert
			7,					// Print_Numbers
			3, 2,				// Safe_Delete
			7,					// Print_Numbers
			4, 					// Sort
			7,					// Print_Numbers
			1, 49, 22, 43, 22, 19, 49, -1,	// Input_Numbers
			7,					// Print_Numbers
			5, 					// Sort_And_Remove_Duplicates
			7,					// Print_Numbers
			6,					// Sum
			0 };					// Quit

	int test_number = test_your_code_with_these_numbers[counter++];
	cout << test_number << endl;
	return test_number;
}

/* Prints the value and position of each element in the vector
 *
 * input: numbers vector
 * output: the values and positions of each element in the vector
 */
void Print_Numbers(vector<int> numbers) {
    cout << "The numbers in the vector are:" << endl;
    for (int i = 0; i < numbers.size(); i++)
        cout << "The value at position [" << i << "] is " << numbers[i] << endl;
}

/* Allows the user to insert values to an emptied numbers vector
 *
 * input: numbers vector
 * output: updated numbers vector
 */
void Input_Numbers(vector<int> &numbers) {
    numbers.clear(); // Empties vector for the new user values
    int input = 0;
    while (input != -1) { // Stop prompting when -1 is entered
        cout << "Please enter a number or -1 to quit: ";
        input = Get_User_Input();
        if (input != -1) { // -1 is never stored
            numbers.push_back(input);
        }
    }
}

/* Inserts the given value to the given index in the numbers vector
 *
 * input: numbers vector
 * output: updated numbers vector
 */
void Safe_Insert(vector<int> &numbers) {
    cout << "Enter the index where you would like to insert a number: ";
    int index = Get_User_Input();
    cout << "Enter the number to be inserted: ";
    int input = Get_User_Input();
    vector<int> temp; // Temporary vector to which we will add all original elements and the new user value
    int end = numbers.size();
    if (index < 0) { // If given index is negative, add user value before anything else
        temp.push_back(input);
        end--; // Decrement the effective size of vector so we don't add user value to the end
    }
    for (int i = 0; i < numbers.size(); i++) {
        if (i != index) // // Will add all original elements of numbers vector
            temp.push_back(numbers[i]);
        else {
            temp.push_back(input);  // When i = index, first add user value
            temp.push_back(numbers[i]); // Then add the element that used to be at the given index
        }
    }
    if (index > end - 1) // If given index is > size of vector, add user value last
        temp.push_back(input);
    numbers = temp; // Updates numbers vector
}

/* Deletes the value at the given index in the numbers vector
 *
 * input: numbers vector
 * output: updated numbers vector
 */
void Safe_Delete(vector<int> &numbers) {
    cout << "Enter the index where you would like to delete a number: ";
    int index = Get_User_Input();
    vector<int> temp; // Temporary vector to which we will add all original elements but the one at the given index
    int i = 0;
    int end = numbers.size();
    if (index < 0) { // If given index is negative, we skip adding the first element
        i = 1;
        end--; // Decrement the effective size of vector so we don't re-add last element
    }
    for (i; i < numbers.size() - 1; i++) {
        if (i != index) // Will add all original elements of numbers vector except for the value at the given index
            temp.push_back(numbers[i]);
    }
    if (index < end - 1) // Will only add last element of numbers vector if index is <= size of vector
        temp.push_back(numbers[numbers.size() - 1]);
    numbers = temp; // Updates numbers vector
}

/* Sorts the numbers vector by ascending order
 *
 * input: numbers vector
 * output: sorted numbers vector
 */
void Sort_Numbers(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());
}

/* Sorts the numbers vector by ascending order and removes duplicates
 *
 * input: numbers vector
 * output: sorted numbers vector without duplicates
 */
void Sort_And_Remove_Duplicates(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end()); // Removes duplicates
}

/* Computes and returns the sum of the numbers vector
 *
 * input: numbers vector
 * output: sum of numbers vector
 */
int Sum(vector<int> numbers) {
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++)
        sum += numbers[i];
    return sum;
}

// #### DO ALL OF YOUR WORK ABOVE THIS LINE!!! ###
// #### We will copy and paste everything above into the grading script for testing
int main() {
	counter = 0;
	vector<int> numbers;
	int total = 0;
	int choice = 1;

	cout << "0. Quit" << endl;
	cout << "1. Input_Numbers" << endl;
	cout << "2. Safe_Insert" << endl;
	cout << "3. Safe_Delete" << endl;
	cout << "4. Sort_Numbers" << endl;
	cout << "5. Sort_And_Remove_Duplicates" << endl;
	cout << "6. Sum" << endl;
	cout << "7. Print_Numbers" << endl << endl;

	while (choice) {
		cout << "Choose one of the menu options: ";
		choice = Get_User_Input();

		switch (choice) {
		case 0:
			break;
		case 1:
			Input_Numbers(numbers);
			break;
		case 2:
			Safe_Insert(numbers);
			break;
		case 3:
			Safe_Delete(numbers);
			break;
		case 4:
			Sort_Numbers(numbers);
			break;
		case 5:
			Sort_And_Remove_Duplicates(numbers);
			break;
		case 6:
			total = Sum(numbers);
			cout << "The total is " << total << endl;
			break;
		case 7:
			Print_Numbers(numbers);
			break;
		default:
			break;
		}
		cout << endl;
	}

	return 0;
}

/* Sample Run using the test_your_code_with_these_numbers in Get_User_Input
0. Quit
1. Input_Numbers
2. Safe_Insert
3. Safe_Delete
4. Sort_Numbers
5. Sort_And_Remove_Duplicates
6. Sum
7. Print_Numbers

Choose one of the menu options: 1
Please enter a number or -1 to quit: 28
Please enter a number or -1 to quit: 13
Please enter a number or -1 to quit: 43
Please enter a number or -1 to quit: -1

Choose one of the menu options: 7
The numbers in the vector are:
The value at position [0] is 28
The value at position [1] is 13
The value at position [2] is 43

Choose one of the menu options: 2
Enter the index where you would like to insert a number: 1
Enter the number to be inserted: -1

Choose one of the menu options: 7
The numbers in the vector are:
The value at position [0] is 28
The value at position [1] is -1
The value at position [2] is 13
The value at position [3] is 43

Choose one of the menu options: 3
Enter the index where you would like to delete a number: 2

Choose one of the menu options: 7
The numbers in the vector are:
The value at position [0] is 28
The value at position [1] is -1
The value at position [2] is 43

Choose one of the menu options: 4

Choose one of the menu options: 7
The numbers in the vector are:
The value at position [0] is -1
The value at position [1] is 28
The value at position [2] is 43

Choose one of the menu options: 1
Please enter a number or -1 to quit: 49
Please enter a number or -1 to quit: 22
Please enter a number or -1 to quit: 43
Please enter a number or -1 to quit: 22
Please enter a number or -1 to quit: 19
Please enter a number or -1 to quit: 49
Please enter a number or -1 to quit: -1

Choose one of the menu options: 7
The numbers in the vector are:
The value at position [0] is 49
The value at position [1] is 22
The value at position [2] is 43
The value at position [3] is 22
The value at position [4] is 19
The value at position [5] is 49

Choose one of the menu options: 5

Choose one of the menu options: 7
The numbers in the vector are:
The value at position [0] is 19
The value at position [1] is 22
The value at position [2] is 43
The value at position [3] is 49

Choose one of the menu options: 6
The total is 133

Choose one of the menu options: 0
*/
