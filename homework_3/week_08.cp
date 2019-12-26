#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <map>

using namespace std;

void set_example() {
	cout << "SET EXAMPLE" << endl;
	cout << "Initialize set" << endl;
	set<string> avengers { "Thor", "Hulk", "Captain America", "Iron Man",
			"Black Widow" };
	for (auto e : avengers)
		cout << e << endl;
	cout << endl;

	//*
	cout << "add Vision" << endl;
	avengers.insert("Vision");

	// adding returns an iterator and boolean as a pair
	// http://www.cplusplus.com/reference/utility/pair/
	// grab the iterator by accessing the first element pair
	cout << "add Hawkeye" << endl;
	set<string>::iterator p = avengers.insert("Hawkeye").first;

	for (auto e : avengers)
		cout << e << endl;
	cout << endl;

	cout << "pointer to Hawkeye and the avenger after Hawkeye" << endl;
	cout << *p << endl;
	p++;
	cout << *p << endl << endl;
	//*/

	//*
	cout << "adding more avengers" << endl;
	vector<string> more_avengers { "Spiderman", "Ant-man", "Wasp",
			"Black Panther" };

	avengers.insert(more_avengers.begin(), more_avengers.end());
	for (auto e : avengers)
		cout << e << endl;
	cout << endl;
	// */

	//*
	cout << "lower_bound / upper_bound example" << endl;
	for (set<string>::iterator it = avengers.lower_bound("Black Panther");
			it != avengers.upper_bound("Hulk"); it++)
		cout << *it << endl;
	cout << endl;
	//*/
}

void unordered_set_example() {
	cout << "UNORDERED SET EXAMPLE" << endl;
	cout << "Initialize unordered set" << endl;
	unordered_set<string> avengers { "Thor", "Hulk", "Captain America",
			"Iron Man", "Black Widow" };
	for (auto e : avengers)
		cout << e << endl;
	cout << endl;

	//*
	cout << "add Hawkeye" << endl;
	auto p = avengers.insert("Hawkeye").first;
	for (auto e : avengers)
		cout << e << endl;
	cout << endl;

	cout << "pointer to Hawkeye and avenger after Hawkeye" << endl;
	cout << *p << endl;
	p++;
	cout << *p << endl << endl;
	// */

	//*
	cout << "adding more avengers" << endl;
	vector<string> more_avengers { "Spiderman", "Ant-man", "Wasp",
			"Black Panther" };

	avengers.insert(more_avengers.begin(), more_avengers.end());
	for (auto e : avengers)
		cout << e << endl;
	cout << endl;
	// */
}

void map_example() {
	map<string, float> fruit_to_price { pair<string, float>("apple", 1.9), pair<
			string, float>("pear", 2.99) };
	for (auto e : fruit_to_price)
		cout << left << setw(7) << e.first << fixed << setprecision(2)
				<< setw(4) << e.second << endl;
	cout << endl;

	//*
	cout << "Add grapes" << endl;
	fruit_to_price["grapes"] = 4.99;
	for (auto e : fruit_to_price)
		cout << left << setw(7) << e.first << fixed << setprecision(2)
				<< setw(4) << e.second << endl;
	cout << endl;
	// */
}

/* struct template
 struct type_name_of_struct {
 variable_type_1 variable_1;
 variable_type_2 variable_2;
 variable_type_3 variable_3;
 .
 .
 } object_names;
 */

struct MOVIE_RATING {
	string title;
	int stars;
} jasons_favorite_movie, film[3];

/*
	class class_name {
	  access_specifier_1:
	    member1;
	  access_specifier_2:
	    member2;
	  ...
	} object_names;
*/

int main() {
	 set_example();
	 unordered_set_example();
	 map_example();

	// struct - encapsulates data into an object
	MOVIE_RATING mikes_favorite_movie;
	mikes_favorite_movie.title = "Avengers";
	mikes_favorite_movie.stars = 10;
	cout << mikes_favorite_movie.title << " - " << mikes_favorite_movie.stars << " stars" << endl;
	jasons_favorite_movie.title = "Sharknado 6";
	jasons_favorite_movie.stars = 1;
	cout << jasons_favorite_movie.title << " - " << jasons_favorite_movie.stars << " stars" << endl;

	// struct with object names in definition
	// see above definition of MOVIE_RATING

	// accessing data members
	// use . notation

	// arrays of objects use brackets after the object name then . to access the member variables
	film[0].title = "Iron Man 2";
	film[0].stars = 9;
	film[1].title = "Thor";
	film[1].stars = 8;
	film[2].title = "Terminator";
	film[2].stars = 6;

	// pointers to structures use -> instead of . to access
	MOVIE_RATING *p_film = &mikes_favorite_movie;
	cout << p_film->title << " - " << p_film->stars << " stars" << endl;
	// (*pointer).member is the same as using the -> but not as easy to type
	cout << (*p_film).title << " - " << (*p_film).stars << " stars" << endl;

	return 0;
}
