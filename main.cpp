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
	int dcCount = 0;
	int marvelCount = 0;

	//Main page of the project
	cout << "Welcome to your favorite Marvel/DC Comics movies and shows inventory!" << endl;
	cout << "Please enter the file you would like to add a movie/show to(dc or marvel): ";
	getline(cin, fileName);

	//Dc File
	if (fileName == "dc") {
		ofstream dcFile("dc.txt");
		
		cout << endl << "Welcome to the DC file! " << endl;
		cout << "Please enter your favorite Marvel shows/movies!(Type 'end' to stop)" << endl;

		//inputting DC titles
		for (int i = 0; i < MAX; i++) {
			cout << "Title " << i + 1 << ": ";
			getline(cin, dcProject[i].title);

			if (dcProject[i].title == "end") {
				break;
			}
			dcCount++;
		}

		//inputting DC ratings
		cout << endl << "Please enter your ratings (out of 10.0)" << endl;
		for (int i = 0; i < dcCount; i++) {
			cout << dcProject[i].title << ": ";
			cin >> dcProject[i].rating;
		}
		
		
		int dcHighest = dcProject[0].rating;
		string dcFav = dcProject[0].title;
		//highest rated DC project
		for (int i = 1; i < dcCount; i++) {
			if (dcProject[i].rating > dcHighest) {
				dcHighest = dcProject[i].rating;
				dcFav = dcProject[i].title;
			}
		}
		cout << "Your favorite DC project is " << dcFav << "!" << endl;
			
	
		

	}

	//Marvel File
	 if (fileName == "marvel") {
		ofstream marvelFile("marvel.txt");

		cout << endl << "Welcome to the Marvel file! " << endl;
		cout << "Please enter your favorite Marvel shows/movies!(Type 'end' to stop)" << endl;

		//inputting Marvel titles
		for (int i = 0; i < MAX; i++) {
			cout << "Title " << i + 1 << ": ";
			getline(cin, marvelProject[i].title);
			if (marvelProject[i].title == "end") {
				break;
			}
			marvelCount++;
		}

		//inputting Marvel ratings
		cout << endl << "Please enter your ratings (out of 10.0)" << endl;
		for(int i = 0; i < marvelCount; i++){
			cout << marvelProject[i].title << ": ";
			cin >> marvelProject[i].rating;
		}
			
		int marvelHighest = marvelProject[0].rating;
		string marvelFav = marvelProject[0].title;

		//highest rated Marvel project
		for (int i = 1; i < marvelCount; i++) {
			if (marvelProject[i].rating > marvelHighest) {
				marvelHighest = marvelProject[i].rating;
				marvelFav = marvelProject[i].title;
			}
		}
		cout << "Your favorite Marvel project is " << marvelFav << "!" << endl;
		
	}

    return 0;
}
