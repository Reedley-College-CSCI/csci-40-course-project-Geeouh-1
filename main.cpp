// CSCI-40 Final Project
// Author: Giovanni Sosa

/* 
 * This project is an inventory management system for Marvel and DC Comics movies and shows.
 * The user wil be able to store their favorite movies/shows from Marvel and DC Comics and 
 * input them in a file. Each universe will have its own file (marvel.txt and dc.txt). 
 * There will one file that will store all the movies/shows from both(all.txt).
 * The user will be asked for the title and their personal rating out of 10.0. They will be
 * able to view, add, remove, and sort the movies/shows in the inventory by title or rating.
 *
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 20;

struct movieShow {
	string title;
	double rating;
};

int main() {
	
	string fileName;

	movieShow dcProject[MAX];
	movieShow marvelProject[MAX];
	
	int i = 0;
	cout << "Welcome to your favorite Marvel/DC Comics movies and shows inventory!" << endl;
	cout << "Please enter the file you would like to add a movie/show to(dc or marvel): ";
	getline(cin, fileName);

	if (fileName == "dc") {
		ofstream dcFile("dc.txt");

		cout << endl << "Welcome to the DC file! " << endl;
		cout << "Enter your favorite DC shows/movies!" << endl;
		for(int i = 0; i < MAX; i++){
			cout << "Title " << i + 1 << ": ";
			getline(cin, dcProject[i].title);
			
			cout << "Rating (out of 10.0): ";
			cin >> dcProject[i].rating;
			
		
		}
	}
	else if (fileName == "marvel") {
		ofstream marvelFile("marvel.txt");
		cout << endl << "Welcome to the Marvel file! " << endl;


		cout << "Please enter your favorite Marvel shows/movies!(Type 'end' to stop)" << endl;
		
			for (int i = 0; i < MAX; i++) {
				cout << "Title " << i + 1 << ": ";
				getline(cin, marvelProject[i].title);
				
				cout << "Rating " << i + 1 << " (out of 10.0): ";
				cin >> marvelProject[i].rating;
		
			}
			
			
		cout << "thank you" << endl;
		
	}
    return 0;
}
