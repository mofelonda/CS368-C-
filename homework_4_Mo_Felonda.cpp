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
#include <map>
#include <vector>
#include <set>
#include <string>
#include <time.h>

using namespace std;

// feel free to use this function if you wish
// purpose: generate random coordinates
// input: none
// output: a vector with 2 coordinates between 1,1 and 4,4
vector<int> Get_A_Random_Square() {
	return vector<int>{rand()%4+1, rand()%4+1};
}

// feel free to use this function if you wish
// purpose: verifies if the coordinates of a square fall within the cave
// input: coordinates of a square
// output: true if the square is in the cave otherwise false
bool Is_Square_Valid(const vector<int> &square) {
	for (auto e : square)
		if (e < 1 || e > 4)
			return false;
	return true;
}

// don't change this function
// purpose: prints a map of the cave to the console
// input: the printable map a vector of strings
// output: none - console output of the cave diagram
void Print_Cave_Diagram(const vector<string> &cave_diagram){
	for (auto s : cave_diagram)
		cout<<s<<endl;
}

// Implement these functions below
// Do not change the function prototpyes
void Initialize_Cave(map<vector<int>, set<string> > &cave);
void Print_Square(map<vector<int>, set<string> > &cave, const vector<int> &rc);
void Get_Cave_Diagram(map<vector<int>, set<string> > &cave, vector<string> &cave_diagram);

// sample main function
int main() {
	srand(time(NULL)); // seed the random generator

	// Declare the cave data structure to 'map' coordinates to a 'set' of strings describing the cell contents
	map<vector<int>, set<string> > cave;

	// Check this out! The cave data structure has a lot going on
	// Uncomment the block below to see a demo of how to use the cave map
	// use the [] to access the set contained in the map
	// insert puts the word "ladder" into the set
	// cave[rc] is the set of words at coordinates rc
	// cave[rc].begin() returns an iterator to the first element of the set
	// note your program will likely crash if the set is empty
	// I recommend checking for this.
	// use the * to dereference the pointer to get the first word stored in the set
	/*
	vector<int> rc{1, 1}; // row column
	cave[rc].insert("ladder");
	if (cave[rc].empty() == false)
		cout<<"cave square (1,1) contains a "<<*cave[rc].begin()<<endl;
	// */

	Initialize_Cave(cave);

	for (int r=1; r<=4; r++) {
		for (int c=1; c<=4; c++) {
			vector<int> rc{r, c};
			Print_Square(cave, rc);
		}
	}

	vector<string> cave_diagram;
	Get_Cave_Diagram(cave, cave_diagram);
	Print_Cave_Diagram(cave_diagram);

	return 0;
}

// helper method to add the stench or breeze to the map
// input: map, cave, wumpus coordinates, air-emitter coordinates (wumpus or pit)
// output: stench or breeze to cave
void placeAir(map<vector<int>, set<string> > &cave, const vector<int> &wumpus, const vector<int> &square) {
    string air = "breeze";
    if (wumpus == square) { // insert stench if the pertinent square is the wumpus square
        air = "stench";
    }
    // left (x - 1)
    if (Is_Square_Valid({square[0] - 1, square[1]})) {
        cave[{square[0] - 1, square[1]}].insert(air);
    }
    // right (x + 1)
    if (Is_Square_Valid({square[0] + 1, square[1]})) {
        cave[{square[0] + 1, square[1]}].insert(air);
    }
    // up (y + 1)
    if (Is_Square_Valid({square[0], square[1] + 1})) {
        cave[{square[0], square[1] + 1}].insert(air);
    }
    // down (y - 1)
    if (Is_Square_Valid({square[0], square[1] - 1})) {
        cave[{square[0], square[1] - 1}].insert(air);
    }
}

// add the player, ladder, wumpus, pits, gold, stench, breeze to the map
// input: map, cave
// output: elements to cave
void Initialize_Cave(map<vector<int>, set<string> > &cave) {
	// place the "ladder" in row 1 column 1
    vector<int> ladder{1,1};
    cave[ladder].insert("ladder");

    // place the "player" at the same location as the ladder
    cave[ladder].insert("player");

	// place the "wumpus" - can't be in the same square as the ladder
	vector<int> wumpus{1,1};
	while (wumpus == ladder) {
        wumpus = Get_A_Random_Square();
	}
    cave[wumpus].insert("wumpus");

	// place the 3 "pits" - can't be in the same square as the ladder, wumpus, or another pit
	vector<int> pit1{1,1};
    vector<int> pit2{1,1};
    vector<int> pit3{1,1};
    while (pit1 == ladder || pit1 == wumpus) {
        pit1 = Get_A_Random_Square();
    }
    while (pit2 == ladder || pit2 == wumpus || pit2 == pit1) {
        pit2 = Get_A_Random_Square();
    }
    while (pit3 == ladder || pit3 == wumpus || pit3 == pit1 || pit3 == pit2) {
        pit3 = Get_A_Random_Square();
    }
    cave[pit1].insert("pit");
    cave[pit2].insert("pit");
    cave[pit3].insert("pit");

	// place the "gold" - can't be in the same square as a pit or the ladder
	vector<int> gold{1,1};
    while (gold == ladder || gold == pit1 || gold == pit2 || gold == pit3) {
        gold = Get_A_Random_Square();
    }
    cave[gold].insert("gold");

	// place the "stench" squares to the left, right, up, and down from the wumpus
	placeAir(cave, wumpus, wumpus);

	// place the "breeze" squares to the left, right, up, and down from the three pits
    placeAir(cave, wumpus, pit1);
    placeAir(cave, wumpus, pit2);
    placeAir(cave, wumpus, pit3);

}


// print the contents of the square
// input: map, cave, row-col coordinates
// output: cave cell contents
void Print_Square(map<vector<int>, set<string> > &cave, const vector<int> &rc) {
    cout << "This part of the cave contains" << endl;
    if (cave[rc].empty()) {
        cout << "    nothing" << endl;
    }
    else {
        for (auto elem : cave[rc]) {
            cout << "    " << elem << endl;
        }
    }
    cout << endl; // extra endl according to example output
}

// build a vector of strings where each string in the vector represents one row of the cave output
// input: map, cave, initial cave diagram
// output: game start cave diagram
void Get_Cave_Diagram(map<vector<int>, set<string> > &cave, vector<string> &cave_diagram) {
	int cell_rows = 5;
	int cell_columns = 11;
	int total_rows = cell_rows*4 + 1;
	int total_columns = cell_columns*4 + 1;

	// fill in with vertical cell divisions
	for (int r=0; r<total_rows; r++) {
		string row(total_columns, ' ');
		for (int c=0; c<total_columns; c+=cell_columns) {
			row[c] = '|';
		}
		cave_diagram.push_back(row);
	}

	// udpate horizontal rows with '-'
	for (int i=0; i<total_rows; i+=cell_rows) {
		cave_diagram[i] = string(total_columns, '-');
	}

	// update cell corners with '+'
	for (int r=0; r<total_rows; r+=cell_rows) {
		for (int c=0; c<total_columns; c+=cell_columns) {
			cave_diagram[r][c]='+';
		}
	}

	// replace the part of the string with the cell contents
    for (int r = 1; r <= 4; r++) { // iterate through rows
        for (int c = 1; c <= 4; c++) { // iterate through columns
            if (!cave[{r,c}].empty()) { // skip cell if no elements present
                for (int i = 0; i < cave[{r,c}].size(); i++) { // iterate through cell contents
                    string elem = *next(cave[{r,c}].begin(), i); // store cell element
                    for (int j = 0; j < elem.length(); j++) { // iterate through chars of cell element
                        cave_diagram[1 + (r - 1) * 5 + i][3 + (c - 1) * 11 + j] = elem[j]; // add char to diagram
                    }
                }
            }
        }
    }
}