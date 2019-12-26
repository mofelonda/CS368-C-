/* ******************************************************
 * Name: Mo Felonda
 * Wisc ID: felonda, 9073207327
 * OS: macOS Catalina
 * IDE (or text editor): CLion
 * Compiler: CMake
 * How long did the assignment take you to complete in minutes: 60~
 * What other resources did you consult (copy and paste links below): N/A
*/ // ******************************************************

// note the grading script will only allow these include files - do not add extra #includes
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int MAX_CLASS_SIZE = 100;
const int MAX_NUMBER_OF_ASSIGNMENTS = 100;

// do not change these prototypes.  Add your code to the function definitions below
void Read_Grade_File(string names[MAX_CLASS_SIZE][2], int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS],
                            int *number_of_students, int *number_of_assignments, const string input_filename);
void Format_Case_Of_Names(string names[MAX_CLASS_SIZE][2], const int number_of_students);
void Compute_Total_And_Percent(int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS], int total[], float percent[],
                                                                int number_of_students, int number_of_assignments);
void Write_Formatted_Grades(string names[MAX_CLASS_SIZE][2], int total[], float percent[],
                                const int number_of_students, const string output_filename);

// There is no need to change main. However you are encouraged to write code
// that writes data to the console to check the correctness of each of your functions as
// as you work.
int main() {
	string input_filename="unformatted_grades.txt";
	string output_filename="formatted_grades.txt";
	string names[MAX_CLASS_SIZE][2];
	int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS];
	int number_of_students=0;
	int number_of_assignments=0;
	int total[MAX_CLASS_SIZE];
	float percent[MAX_CLASS_SIZE];

	Read_Grade_File(names, scores, &number_of_students, &number_of_assignments, input_filename);
	Format_Case_Of_Names( names, number_of_students);
	Compute_Total_And_Percent( scores, total, percent, number_of_students, number_of_assignments);
	Write_Formatted_Grades(names, total, percent, number_of_students, output_filename);
	return 0;
}

// Reads input from nonformatted files
// input: nonformatted grade file
// output: student name array, score array, # students, # assignments
void Read_Grade_File(string names[MAX_CLASS_SIZE][2], int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS],
                            int *number_of_students, int *number_of_assignments, const string input_filename){
    ifstream in;
    in.open(input_filename);
    string blah;
    in >> blah >> *number_of_students >> blah >> *number_of_assignments;
    for (int i = 0; i < *number_of_assignments + 3; i ++) {
        in >> blah;
    }
    for (int i = 0; i < *number_of_students; i++) {
        in >> blah >> names[i][0] >> names[i][1];
        for (int j = 0; j < *number_of_assignments; j++) {
             in >> scores[i][j];
        }
    }
    in.close();
}

// Formats names array so that names are lowercase capitalized
// input: nonformatted names array, # students
// output: formatted names array
void Format_Case_Of_Names(string names[MAX_CLASS_SIZE][2], const int number_of_students){
    for (int i = 0; i < number_of_students; i++) {
        if (names[i][0].at(0) > 96) {
            names[i][0].at(0) -= 32;
        }
        if (names[i][1].at(0) > 96) {
            names[i][1].at(0) -= 32;
        }
        for (int j = 1; j < names[i][0].size(); j++) {
            if (names[i][0].at(j) < 96) {
                names[i][0].at(j) += 32;
            }
        }
        for (int j = 1; j < names[i][1].size(); j++) {
            if (names[i][1].at(j) < 96) {
                names[i][1].at(j) += 32;

            }
        }
    }
}

// Computes total points and percentage correct for each student
// input: score array, # students, # assignments
// output: total points array, percentage correct array
void Compute_Total_And_Percent(int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS], int total[], float percent[],
                                                                int number_of_students, int number_of_assignments){
    for (int i = 0; i < number_of_students; i++) {
        for (int j = 0; j < number_of_assignments; j++) {
            total[i] += scores[i][j];
        }
        percent[i] = total[i] / (float)(number_of_assignments * 10) * 100;
    }
}

// Outputs formatted grades to a file
// input: formatted name array, total points array, percentage correct array, # students, # assignments
// output: formatted grade file
void Write_Formatted_Grades(string names[MAX_CLASS_SIZE][2], int total[], float percent[],
                                const int number_of_students, const string output_filename){
    string student[MAX_CLASS_SIZE];
    ofstream out;
    out.open(output_filename);
    for (int i = 0; i < number_of_students; i++) {
        student[i] = names[i][1] + ", " + names[i][0];
        out << left << setw(20) << student[i] << total[i] << right <<
            setw(7) << fixed << setprecision(1) << percent[i] << endl;
    }
    out.close();
}