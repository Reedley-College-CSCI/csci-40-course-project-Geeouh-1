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

void openDCFile(movieShow dcTitle[], int& dcCount) {
	ifstream dcFile;
	dcFile.open("dc.txt");
	if (!dcFile) {
		cout << "Error opening file!" << endl;
		return;
	}
	while (dcFile >>  dcTitle[dcCount].title >> dcTitle[dcCount].rating){
		cout << dcTitle[dcCount].title << " " << dcTitle[dcCount].rating << endl;
	}
	dcFile.close();
}
void openMarvelFile() {
	ifstream marvelFile;
	marvelFile.open("marvel.txt");
	if (!marvelFile) {
		cout << "Error opening file!" << endl;
		return;
	}
	
	marvelFile.close();
}


int main() {
	
	string fileName;

	movieShow *dcProject = new movieShow[MAX];
	movieShow *marvelProject = new movieShow[MAX];
	int dcCount = 0;
	int marvelCount = 0;

	//Main page of the project
	cout << "Welcome to your favorite Marvel/DC Comics movies and shows inventory!" << endl;
	cout << "Please enter the file you would like to add a movie/show to(dc or marvel): ";

	while (fileName != "exit") {

		getline(cin, fileName);
	
	//Exit Program
	if (fileName == "exit") {
		cout << "Exiting program..." << endl;
		break;
	}

	//Dc File
	if (fileName == "dc") {
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
		for(int i = 0; i < dcCount; i++){
			dcFile << dcProject[i].title << ": " << dcProject[i].rating << endl;
		}
		dcFile.close();
		cout << "DC file has been updated!" << endl;
		cout << endl << "Please enter the file you would like to add a movie/show to(dc or marvel): ";
	}

	//Marvel File
	if (fileName == "marvel") {

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
		marvelFile.close();
		cout << "Marvel file has been updated!" << endl;
		cout << endl << "Please enter the file you would like to add a movie/show to(dc or marvel): ";
	}

  }
	cout << "Would you like to view the contents of the files? (yes/no): ";
	string viewFiles;
	cin >> viewFiles;
	if (viewFiles == "yes") {
		cout << "What file would you like to view? (dc/marvel): ";
		string viewFileName;
		cin >> viewFileName;
		if (viewFileName == "dc") {
			openDCFile(dcProject, dcCount);
		}
		else if (viewFileName == "marvel") {
			openMarvelFile();
		}
		else {
			cout << "Invalid file name!" << endl;
		}
	}
	 delete[] dcProject;
	 delete[] marvelProject;
	 
	 return 0;
}
