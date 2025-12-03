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

const int MAX = 50;

struct movieShow {
	string title;
	double rating;
};
//allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen

//Reading files
void openDCFile(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen);
void openMarvelFile(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen);
void openAllFile(movieShow allTitle[], int& allCount);
//Option choices
void viewFile(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen);
void sortByRating(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen);
void addTitle(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen);
//Sorting functions
void sortRatingDC(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen);
void sortRatingAll(movieShow allTitle[], int& allCount);
void sortRatingMarvel(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen);
//Options Menu
void optionsMenu(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen);

int main() {

	string fileName;

	movieShow* dcProject = new movieShow[MAX];
	movieShow* marvelProject = new movieShow[MAX];
	movieShow* allProject = new movieShow[MAX];
	int dcCount = 0;
	int marvelCount = 0;
	int allCount = 0;
	int dcOpen = 0;
	int marvelOpen = 0;
	//Main page of the project
	cout << " -- Welcome to your favorite Marvel/DC Comics movies and shows inventory! -- " << endl;
	cout << "Please enter the file you would like to add a movie/show to('dc' or 'marvel'): ";

	ofstream allFile;
	allFile.open("allProjects.txt");
	while (true) {

		getline(cin, fileName);

		if (fileName == "dc") {
			if (dcOpen == 1) {
				if (fileName == "dc") {
					cout << endl;
					cout << "Can't add to DC File right now. Please wait until the Options Menu." << endl;
					cout << "Please choose another file to add to('marvel' or 'exit' to leave): ";
					continue;
				}
			}
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
				string DCinput;
				cout << "Title " << i + 1 << ": ";
				getline(cin, dcProject[i].title);
				if (dcProject[i].title == "end") {
					break;
				}
				cout << dcProject[i].title << "'s rating: ";
				getline(cin, DCinput);
				try {
					double rating = stod(DCinput);
					if (rating > 0.0 && rating <= 10.0) {
						dcProject[i].rating = rating;
					}
					else {
						cout << "Rating must be between 0.0 and 10.0" << endl;
						i--;
						continue;
					}
				}
				catch (invalid_argument&) {
					cout << "Invalid rating input! Please enter a numeric value." << endl;
					i--;
					continue;
				}
				catch (out_of_range&) {
					cout << "out of range!" << endl;
					i--;
					continue;
				}
				
				

				dcFile << dcProject[i].title << ": " << dcProject[i].rating << endl;
				allFile << dcProject[i].title << ": " << dcProject[i].rating << endl;
				allProject[i].title = dcProject[i].title;
				allProject[i].rating = dcProject[i].rating;
				dcCount++;
				allCount++;
			}
			dcOpen++;
			dcFile.close();
			//After DC File is done, user will choose to leave or go to Marvel file
				cout << "DC file has been updated!" << endl;
				if (dcOpen == 1 && marvelOpen == 1) {
					cout << endl << endl;
					cout << "Both files have been updated! Proceeding to Options Menu..." << endl;
					break;
				}
				cout << "Please choose another file to add to('marvel' or 'exit' to leave): ";
			
				
		}	
		if (fileName == "marvel") {
			if (marvelOpen == 1) {
				if (fileName == "marvel") {
					cout << endl;
					cout << "Can't add to Marvel File right now. Please wait until the Options Menu." << endl;
					cout << "Please choose another file to add to('dc' or 'exit' to leave): ";
					continue;
				}
			}
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
				string marvelInput;
				cout << "Title " << i + 1 << ": ";
				getline(cin, marvelProject[i].title);
				if (marvelProject[i].title == "end") {
					break;
				}
				cout << marvelProject[i].title << "'s rating: ";
				getline(cin, marvelInput);
				try {
					double rating = stod(marvelInput);
					if (rating > 0.0 && rating <= 10.0) {
						marvelProject[i].rating = rating;
					}
					else {
						cout << "Rating must be between 0.0 and 10.0" << endl;
						i--;
						continue;
					}
				}
				catch (invalid_argument&) {
					cout << "Invalid rating input! Please enter a numeric value." << endl;
					i--;
					continue;
				}
				catch (out_of_range&) {
					cout << "out of range!" << endl;
					i--;
					continue;
				}

				marvelFile << marvelProject[i].title << ": " << marvelProject[i].rating << endl;
				allFile << marvelProject[i].title << ": " << marvelProject[i].rating << endl;
				allProject[i].title = marvelProject[i].title;
				allProject[i].rating = marvelProject[i].rating;

				marvelCount++;
				allCount++;
			}
			marvelFile.close();
			marvelOpen++;
			//After Marvel File is done, user will choose to leave or go to DC file
			cout << "Marvel file has been updated!" << endl;
			if (dcOpen == 1 && marvelOpen == 1) {
				cout << endl << endl;
				cout << "Both files have been updated! Proceeding to Options Menu..." << endl;
				break;
			}
			cout << "Please choose another file to add to('dc' or 'exit' to leave): ";
		}
		if(fileName == "exit") {
			cout << "Exiting the program..." << endl;
			break;
		}
		if(fileName != "dc" && fileName != "marvel" && fileName != "exit") {
			cout << "Invalid file name! Enter file name: ";
		}
	}
	allFile.close();

	optionsMenu(allProject, marvelProject, dcProject, allCount, marvelCount, dcCount, marvelOpen, dcOpen);


	delete[] dcProject;
	delete[] marvelProject;
	delete[] allProject;
	return 0;
}

//Options Menu function
void optionsMenu(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[], 
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen) {
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
		viewFile(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}
	if (option == "B" || option == "b") {
		sortByRating(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}
	if (option == "D" || option == "d") {
		addTitle(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}
}
//Reading File functions
void openDCFile(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen) {
	ifstream dcFile;
	dcFile.open("dc.txt");
	if (!dcFile) {
		cout << "Error opening file!" << endl;
		return;
	}
	if (dcOpen == 0) {
		cout << "Riddle me this, why didn't you add to the file!? - Riddler" << endl;
		optionsMenu(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}

	if (marvelOpen == 1) {
		while (dcFile >> dcTitle[dcCount].title >> dcTitle[dcCount].rating) {
			cout << dcTitle[dcCount].title << " " << dcTitle[dcCount].rating << endl;
		}
	}
	dcFile.close();
}
void openMarvelFile(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen) {
	ifstream marvelFile;
	marvelFile.open("marvel.txt");
	if (!marvelFile) {
		cout << "Error opening file!" << endl;
		return;
	}
	if (marvelOpen == 0) {
		cout <<  "You should've added to the file! *Snap* - Thanos" << endl;
		optionsMenu(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}

	if (marvelOpen == 1) {
		while (marvelFile >> marvelTitle[marvelCount].title >> marvelTitle[marvelCount].rating) {
			cout << marvelTitle[marvelCount].title << " " << marvelTitle[marvelCount].rating << endl;
		}
	}
	

	marvelFile.close();
}
void openAllFile(movieShow allTitle[], int& allCount) {
	ifstream allFile;
	allFile.open("allProjects.txt");
	if (!allFile) {
		cout << "Error opening file!" << endl;
		return;
	}
	while (allFile >> allTitle[allCount].title >> allTitle[allCount].rating) {
		cout << allTitle[allCount].title << " " << allTitle[allCount].rating << endl;
	}
	allFile.close();
}
//Option choices Functions
void viewFile(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen) {
	cout << "What file would you like to view? (dc/marvel/all): ";
	string viewFileName;
	cin >> viewFileName;
	cout << endl;
	if (viewFileName == "dc") {
		openDCFile(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}
	else if (viewFileName == "marvel") {
		openMarvelFile(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}
	else if (viewFileName == "all") {
		openAllFile(allTitle, allCount);
	}
	else {
		cout << "Invalid file name!" << endl;
		viewFile(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}
}
void sortByRating(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen) {
	cout << "Which file would you like to sort by rating(dc/marvel/all): ";
	string sortName;
	cin >> sortName;
	cout << endl;

	if (sortName == "dc") {
		sortRatingDC(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}
	if (sortName == "all") {
		sortRatingAll(allTitle, allCount);
	}
	if (sortName == "marvel") {
		sortRatingMarvel(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}
	else {
		cout << "Invalid file name!" << endl;
		sortByRating(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}

}

void addTitle(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen) {

	ofstream marvelFile;
	ofstream dcFile;
	int exCountDC = dcCount;
	int exCountMarvel = marvelCount;
	
	cout << "Which file would you like to add titles to?(dc/marvel): ";
	string addFileName;
	cin >> addFileName;
	cout << endl;
	
	if (addFileName == "dc") {
		//adding to DC file
		dcFile.open("dc.txt", ios::app);
		
		for (int i = dcCount; i < MAX; i++) {
			cout << "Title " << i + 1 << ": ";
			cin.ignore();
			getline(cin, dcTitle[i].title);
			if (dcTitle[i].title == "nd") {
				break;
			}
			cout << dcTitle[i].title << "'s rating: ";
			cin >> dcTitle[i].rating;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			dcCount++;
		}
		for (int i = exCountDC; i < dcCount; i++) {
			dcFile << dcTitle[i].title << ": " << dcTitle[i].rating << endl;
		}
		dcFile.close();
		dcOpen++;
		cout << "DC file has been updated!" << endl;
		optionsMenu(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}
	if (addFileName == "marvel") {
		//adding to marvel file
		marvelFile.open("marvel.txt", ios::app);

		for (int i = marvelCount; i < MAX; i++) {
			cout << "Title " << i + 1 << ": ";
			cin.ignore();
			getline(cin, marvelTitle[i].title);
			if (marvelTitle[i].title == "nd") {
				break;
			}
			cout << marvelTitle[i].title << "'s rating: ";
			cin >> marvelTitle[i].rating;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			marvelCount++;
		}
		for (int i = exCountMarvel; i < dcCount; i++) {
			marvelFile << marvelTitle[i].title << ": " << marvelTitle[i].rating << endl;
		}
		marvelFile.close();

		cout << "Marvel file has been updated!" << endl;
		optionsMenu(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}
	else {
		cout << "Invalid file name!" << endl;
		addTitle(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
	}
	
}
//sorting functions
void sortRatingDC(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen) {
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
		openDCFile(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
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
		openDCFile(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
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
void sortRatingAll(movieShow allTitle[], int& allCount){
	int allRateSort;
	cout << "How would you like to sort the ALL file by rating (highest to lowest)?" << endl;
	cout << "1) Highest to Lowest" << endl;
	cout << "2) Lowest to Highest" << endl;
	cout << endl << "Rating option: ";
	cin >> allRateSort;

	if (allRateSort != 1 && allRateSort != 2) {
		cout << "Invalid option." << endl;
	}

	if (allRateSort == 1) {
		openAllFile(allTitle, allCount);
		cout << endl;
		bool swapped;
		int j = 0;
		do {
			swapped = false;
			for (int i = 0; i < allCount - 1 - j; i++) {

				if (allTitle[i].rating < allTitle[i + 1].rating) {
					double temp = allTitle[i].rating;
					string temp2 = allTitle[i].title;
					allTitle[i].rating = allTitle[i + 1].rating;
					allTitle[i].title = allTitle[i + 1].title;
					allTitle[i + 1].rating = temp;
					allTitle[i + 1].title = temp2;
					swapped = true;
				}
			}
			j++;
		} while (swapped);

		for (int i = 0; i < allCount; i++) {
			cout << allTitle[i].title << ": " << allTitle[i].rating << endl;
		}

	}

	if (allRateSort == 2) {
		openAllFile(allTitle, allCount);
		cout << endl;
		bool swapped;
		int j = 0;
		do {
			swapped = false;
			for (int i = 0; i < allCount - 1 - j; i++) {

				if (allTitle[i].rating > allTitle[i + 1].rating) {
					double temp = allTitle[i].rating;
					string temp2 = allTitle[i].title;
					allTitle[i].rating = allTitle[i + 1].rating;
					allTitle[i].title = allTitle[i + 1].title;
					allTitle[i + 1].rating = temp;
					allTitle[i + 1].title = temp2;
					swapped = true;
				}
			}
			j++;
		} while (swapped);

		for (int i = 0; i < allCount; i++) {
			cout << allTitle[i].title << ": " << allTitle[i].rating << endl;
		}

	}
}
void sortRatingMarvel(movieShow allTitle[], movieShow marvelTitle[], movieShow dcTitle[],
	int& allCount, int& marvelCount, int& dcCount, int& marvelOpen, int& dcOpen){
	int marvelRateSort;
	cout << "How would you like to sort the DC file by rating (highest to lowest)?" << endl;
	cout << "1) Highest to Lowest" << endl;
	cout << "2) Lowest to Highest" << endl;
	cout << endl << "Rating option: ";
	cin >> marvelRateSort;

	if (marvelRateSort != 1 && marvelRateSort != 2) {
		cout << "Invalid option." << endl;
	}

	if (marvelRateSort == 1) {
		openMarvelFile(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
		cout << endl;
		bool swapped;
		int j = 0;
		do {
			swapped = false;
			for (int i = 0; i < marvelCount - 1 - j; i++) {

				if (marvelTitle[i].rating < marvelTitle[i + 1].rating) {
					double temp = marvelTitle[i].rating;
					string temp2 = marvelTitle[i].title;
					marvelTitle[i].rating = marvelTitle[i + 1].rating;
					marvelTitle[i].title = marvelTitle[i + 1].title;
					marvelTitle[i + 1].rating = temp;
					marvelTitle[i + 1].title = temp2;
					swapped = true;
				}
			}
			j++;
		} while (swapped);

		for (int i = 0; i < marvelCount; i++) {
			cout << marvelTitle[i].title << ": " << marvelTitle[i].rating << endl;
		}

	}

	if (marvelRateSort == 2) {
		openMarvelFile(allTitle, marvelTitle, dcTitle, allCount, marvelCount, dcCount, marvelOpen, dcOpen);
		cout << endl;
		bool swapped;
		int j = 0;
		do {
			swapped = false;
			for (int i = 0; i < marvelCount - 1 - j; i++) {

				if (marvelTitle[i].rating > marvelTitle[i + 1].rating) {
					double temp = marvelTitle[i].rating;
					string temp2 = marvelTitle[i].title;
					marvelTitle[i].rating = marvelTitle[i + 1].rating;
					marvelTitle[i].title = marvelTitle[i + 1].title;
					marvelTitle[i + 1].rating = temp;
					marvelTitle[i + 1].title = temp2;
					swapped = true;
				}
			}
			j++;
		} while (swapped);

		for (int i = 0; i < marvelCount; i++) {
			cout << marvelTitle[i].title << ": " << marvelTitle[i].rating << endl;
		}

	}
}