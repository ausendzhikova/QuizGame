#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;

string searchFileName(string& fileName, int& level) {
	switch (level) {
	case 1:
	case 2:
	case 3:
		fileName = "question1.txt";
		break;
	case 4:
	case 5:
	case 6:
		fileName = "question2.txt";
		break;
	case 7:
	case 8:
	case 9:
	case 10:
		fileName = "question3.txt";
	}
	return fileName;
}

void editQuestion(int &level,string &fileName,string &id,string &question, string &A,string &B, string &C,string &D,
	string &correctAns,string &difficultly,string &category,bool &isNotFound) {
	ifstream sourceFile;
	ofstream destinationFile;
	string searchId;
	string newData;
	
	cout << "What is id number of question? ";
	cin >> searchId;
	cout << "What is difficultly of question?";
	cin >> level;

	fileName = searchFileName(fileName,level);
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

	while (getline(sourceFile,id) && getline(sourceFile,question)&&getline(sourceFile,A) && getline(sourceFile, B) && getline(sourceFile, C)
	&& getline(sourceFile, D) && getline(sourceFile, correctAns)&& getline(sourceFile, difficultly)&& getline(sourceFile, category)) {
		if (searchId == id) {
			isNotFound = false;
			cin.ignore();
			destinationFile << id << '\n';
			cout << "Enter a question: ";
			getline(cin, newData);
			destinationFile << newData << '\n';
			cout << "Enter 4 answer: " << endl;
			getline(cin, newData);
			destinationFile << newData << '\n';
			getline(cin, newData);
			destinationFile << newData << '\n';
			getline(cin, newData);
			destinationFile << newData << '\n';
			getline(cin, newData);
			destinationFile << newData << '\n';
			cout << "Which answer is correct?";
			getline(cin, newData);
			destinationFile << newData << '\n';
			destinationFile << level << '\n';
			cout << "What is the category of the question?";
			getline(cin, newData);
			destinationFile << newData << '\n';
		}
		else {
			destinationFile << id << '\n';
			destinationFile << question << '\n';
			destinationFile <<A << '\n';
			destinationFile << B << '\n';
			destinationFile << C << '\n';
			destinationFile << D << '\n';
			destinationFile << correctAns << '\n';
			destinationFile << difficultly << '\n';
			destinationFile <<category  << '\n';




		}
	}

	sourceFile.close();
	destinationFile.close();

	if (fileName == "question1.txt") {
		remove("question1.txt");
		rename("new.txt", "question1.txt");


	}
	else if (fileName == "question2.txt") {
		remove("question2.txt");
		rename("new.txt", "question2.txt");


	}
	else if (fileName == "question3.txt") {
		remove("question3.txt");
		rename("new.txt", "question3.txt");


	}

	return;
}

