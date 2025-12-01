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

void openDCFile(movieShow dcTitle[], int& dcCount);
void openMarvelFile(movieShow marvTitle[], int& marvelCount);
void viewFile(movieShow dcTitle[], int& dcCount, movieShow marvelTitle[], int& marvelCount);
void sortByRating(movieShow dcTitle[], int& dcCount, movieShow marvelTitle[], int& marvelCount);
void sortRatingDC(movieShow dcTitle[], int& dcCount);
int main() {

	string fileName;

	movieShow* dcProject = new movieShow[MAX];
	movieShow* marvelProject = new movieShow[MAX];
	int dcCount = 0;
	int marvelCount = 0;

	//Main page of the project
	cout << "Welcome to your favorite Marvel/DC Comics movies and shows inventory!" << endl;
	cout << "Please enter the file you would like to add a movie/show to(dc or marvel): ";

	while (true) {


		getline(cin, fileName);

		//Exit Program
		if (fileName == "exit") {
			cout << "Exiting program..." << endl;
			break;
		}

		//Dc File
		else if (fileName == "dc") {
			ofstream dcFile;
			dcFile.open("dc.txt");
			if (!dcFile) {
				cout << "Error opening file!" << endl;
				return 1;
			}
			cout << endl << "Welcome to the DC file! " << endl;
			cout << "Please enter your favorite DC shows/movies!(Type 'end' to stop)" << endl;
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
			for (int i = 0; i < dcCount; i++) {
				dcFile << dcProject[i].title << ": " << dcProject[i].rating << endl;
			}
			dcFile.close();
			cout << "DC file has been updated!" << endl;
			cout << endl << "Please enter the file you would like to add a movie/show to(dc/marvel or exit to quit): ";
		}

		//Marvel File
		else if (fileName == "marvel") {

			ofstream marvelFile;
			marvelFile.open("marvel.txt");
			if (!marvelFile) {
				cout << "Error opening file!" << endl;
				return 1;
			}
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
			for (int i = 0; i < marvelCount; i++) {
				cout << marvelProject[i].title << ": ";
				cin >> marvelProject[i].rating;

			}
			for (int i = 0; i < marvelCount; i++) {
				marvelFile << marvelProject[i].title << ": " << marvelProject[i].rating << endl;

			}
			marvelFile.close();
			cout << "Marvel file has been updated!" << endl;
			cout << endl << "Please enter the file you would like to add a movie/show to(dc/marvel or exit to quit): ";
		}


	}
	string option;
	cout << endl;
	cout << "Choose an option!" << endl;
	cout << "A) View Files" << endl;
	cout << "B) Sort by rating" << endl;
	cout << "C) Sort by title" << endl;
	cout << "D) Add more titles" << endl;
	cout << endl << "Option: ";
	cin >> option;
	if (option == "A" || option == "a") {
		viewFile(dcProject, dcCount, marvelProject, marvelCount);
	}
	if (option == "B" || option == "b") {
		sortByRating(dcProject, dcCount, marvelProject, marvelCount);
	}


	 delete[] dcProject;
	 delete[] marvelProject;
	 
	 return 0;
}

void openDCFile(movieShow dcTitle[], int& dcCount) {
	ifstream dcFile;
	dcFile.open("dc.txt");
	if (!dcFile) {
		cout << "Error opening file!" << endl;
		return;
	}
	while (dcFile >> dcTitle[dcCount].title >> dcTitle[dcCount].rating) {
		cout << dcTitle[dcCount].title << " " << dcTitle[dcCount].rating << endl;
	}
	dcFile.close();
}
void openMarvelFile(movieShow marvTitle[], int& marvelCount) {
	ifstream marvelFile;
	marvelFile.open("marvel.txt");
	if (!marvelFile) {
		cout << "Error opening file!" << endl;
		return;
	}
	while (marvelFile >> marvTitle[marvelCount].title >> marvTitle[marvelCount].rating) {
		cout << marvTitle[marvelCount].title << " " << marvTitle[marvelCount].rating << endl;
	}

	marvelFile.close();
}
void viewFile(movieShow dcTitle[], int& dcCount, movieShow marvelTitle[], int& marvelCount) {
	cout << "What file would you like to view? (dc/marvel): ";
	string viewFileName;
	cin >> viewFileName;
	cout << endl;
	if (viewFileName == "dc") {
		openDCFile( dcTitle,  dcCount);
	}
	else if (viewFileName == "marvel") {
		openMarvelFile(marvelTitle, marvelCount);
	}
	else {
		cout << "Invalid file name!" << endl;
	}
}
void sortByRating(movieShow dcTitle[], int& dcCount, movieShow marvelTitle[], int& marvelCount) {
	cout << "Which file would you like to sort by rating(dc/marvel): ";
	string sortName;
	cin >> sortName;
	cout << endl;

	if (sortName == "dc") {
		sortRatingDC(dcTitle, dcCount);
	}


}
void sortRatingDC(movieShow dcTitle[], int& dcCount) {
	int dcRateSort;
	cout << "How would you like to sort the DC file by rating (highest to lowest)?" << endl;
	cout << "1) Highest to Lowest" << endl;
	cout << "2) Lowest to Highest" << endl;
	cout << endl << "Rating option: ";
	cin >> dcRateSort;

	if (dcRateSort != 1 && dcRateSort != 2) {
		cout << "Invalid option." << endl;
	}

	if (dcRateSort == 1) {
		openDCFile(dcTitle, dcCount);
		cout << endl;
		bool swapped;
		int j = 0;
		do {
			swapped = false;
			for (int i = 0; i < dcCount - 1 - j; i++) {

				if (dcTitle[i].rating < dcTitle[i + 1].rating) {
					double temp = dcTitle[i].rating;
					string temp2 = dcTitle[i].title;
					dcTitle[i].rating = dcTitle[i + 1].rating;
					dcTitle[i].title = dcTitle[i + 1].title;
					dcTitle[i + 1].rating = temp;
					dcTitle[i + 1].title = temp2;
					swapped = true;
				}
			}
			j++;
		} while (swapped);

		for (int i = 0; i < dcCount; i++) {
			cout << dcTitle[i].title << ": " << dcTitle[i].rating << endl;
		}

	}

	if (dcRateSort == 2) {
		openDCFile(dcTitle, dcCount);
		cout << endl;
		bool swapped;
		int j = 0;
		do {
			swapped = false;
			for (int i = 0; i < dcCount - 1 - j; i++) {

				if (dcTitle[i].rating > dcTitle[i + 1].rating) {
					double temp = dcTitle[i].rating;
					string temp2 = dcTitle[i].title;
					dcTitle[i].rating = dcTitle[i + 1].rating;
					dcTitle[i].title = dcTitle[i + 1].title;
					dcTitle[i + 1].rating = temp;
					dcTitle[i + 1].title = temp2;
					swapped = true;
				}
			}
			j++;
		} while (swapped);

		for (int i = 0; i < dcCount; i++) {
			cout << dcTitle[i].title << ": " << dcTitle[i].rating << endl;
		}

	}
}
