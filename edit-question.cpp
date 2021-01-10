#include <iostream>
#include <string>
#include <fstream>
#include "transform-validation.h"
using namespace std;

#include "edit-question.h"

string searchFileName(string& fileName, string level) {
	if (level == "1" || level == "2" || level == "3") {
		fileName = "question1.txt";
		return fileName;
	}
	if (level == "4" || level == "5" || level == "6") {
		fileName = "question2.txt";
		return fileName;
	}
	if (level == "7" || level == "8" || level == "9" || level == "10") {
		fileName = "question3.txt";
		return fileName;
	}

	return fileName;
}


void editQuestion(string level, string& fileName, string& id, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, bool& isFound) {
	ifstream sourceFile;
	ofstream destinationFile;
	string searchId;
	string newData;

	
	cout << "What is id number of question? ";
	cin >> searchId;
	
	cin.ignore();
	isEmpty(searchId);

	size_t size = searchId.size();
	for (size_t i = 2; i <size; i++) {
		searchId[i] = tolower(searchId[i]);
	}
	cout << "What is difficultly of question? ";
	getline(cin, level);

	//Validation
	isEmpty(level);
	while (level != "1" && level != "2" && level != "3" && level != "4" && level != "5" && level != "6" && level != "7" && level != "8" && level != "9" && level != "10") {
		cout << "Invalid input! Try again: ";
		getline(cin, level);
	}

	fileName = searchFileName(fileName, level);
	sourceFile.open(fileName);
	if (!sourceFile.is_open()) {
		cout << "Source file doesn't open." << endl;
		return;
	}

	destinationFile.open("new.txt");
	if (!destinationFile.is_open()) {
		cout << "Destination file doesn't open." << endl;
		return;
	}
	//flag for empty file
	bool flag = true;

	while (getline(sourceFile, id) && getline(sourceFile, question) && getline(sourceFile, A) && getline(sourceFile, B) && getline(sourceFile, C)
		&& getline(sourceFile, D) && getline(sourceFile, correctAns) && getline(sourceFile, difficultly) && getline(sourceFile, category)) {
		if (searchId == id) {
			isFound = true;
			//Print question which has to edit
			cout << question << endl;
			cout << "A) " << A << endl;
			cout << "B) " << B << endl;
			cout << "C) " << C << endl;
			cout << "D) " << D << endl;
			cout << "The correct answer is: " << correctAns << endl;
			cout << "The category is: " << category << endl;
			cout << "\n";

			


			if (flag) {
				flag = false;
				destinationFile << id << '\n';
			}
			else {
				destinationFile << '\n' << id << '\n';
			}

			cout << "Enter a question: ";
			getline(cin, newData);
			isEmpty(newData);
			destinationFile << newData << '\n';
			cout << "Enter first answer: ";
			getline(cin, newData);
			isEmpty(newData);
			destinationFile << newData << '\n';
			cout << "Enter second answer: ";
			getline(cin, newData);
			isEmpty(newData);
			destinationFile << newData << '\n';
			cout << "Enter third answer: ";
			getline(cin, newData);
			isEmpty(newData);
			destinationFile << newData << '\n';
			cout << "Enter fourth answer: ";
			getline(cin, newData);
			isEmpty(newData);
			destinationFile << newData << '\n';
			cout << "Which answer is correct? ";
			getline(cin, newData);
			isEmpty(newData);
			newData[0] = tolower(newData[0]);
			while (newData != "a" && newData != "b" && newData != "c" && newData != "d") {
				cout << "Invalid input! Try again: ";
				getline(cin, newData);
				newData[0] = tolower(newData[0]);
			}
			destinationFile << newData << '\n';
			destinationFile << level << '\n';
			cout << "What is the category of the question? ";
			getline(cin, newData);
			isEmpty(newData);
			transformCat(newData,1);
			destinationFile << newData;
		}
		else {
			if (flag) {
				flag = false;
				destinationFile << id << '\n';
			}
			else {
				destinationFile << '\n' << id << '\n';
			}

			destinationFile << question << '\n';
			destinationFile << A << '\n';
			destinationFile << B << '\n';
			destinationFile << C << '\n';
			destinationFile << D << '\n';
			destinationFile << correctAns << '\n';
			destinationFile << difficultly << '\n';
			destinationFile << category;

		
		}
	}

	sourceFile.close();
	destinationFile.close();

	string newName;
	if (fileName == "question1.txt") {
		remove("question1.txt");
		newName=rename("new.txt", "question1.txt");
		return;
	}
	if (fileName == "question2.txt") {
		remove("question2.txt");
		newName=rename("new.txt", "question2.txt");
		return;
	}
	if (fileName == "question3.txt") {
		remove("question3.txt");
		newName=rename("new.txt", "question3.txt");
		return;
	}

	return;
}
