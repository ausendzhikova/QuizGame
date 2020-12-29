#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string readFile(fstream& myFile, string& fileName, string& id, string& question, string& A,
	string& B, string& C, string& D, string& correctAns, string& difficultly, string& category) {
	myFile.open(fileName, fstream::in);
	if (!myFile.is_open()) {
		cout << "File doesn't open" << endl;
	}
	else {
		do {
			getline(myFile, id);
			getline(myFile, question);
			getline(myFile, A);
			getline(myFile, B);
			getline(myFile, C);
			getline(myFile, D);
			getline(myFile, correctAns);
			getline(myFile, difficultly);
			getline(myFile, category);

		} while (myFile.eof());
	}
	myFile.close();
	return id;
}



void writeQuestion(fstream& myFile, string& fileName, string& id, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, int& level) {
	string idNumb = readFile(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category);

	char newId = idNumb[0] + 1;
	id.clear();
	question.clear();
	A.clear();
	B.clear();
	C.clear();
	D.clear();
	correctAns.clear();
	difficultly.clear();
	category.clear();


	myFile.open(fileName, fstream::out | fstream::app);
	if (!myFile.is_open()) {
		cout << "File doesn't open." << endl;
		return;
	}
	else {

		myFile << '\n'<< newId << '\n';
		cin.ignore();

		cout << "Enter a question: ";
		getline(cin, question);
		cout << "Enter 4 answer: " << endl;
		getline(cin, A);
		getline(cin, B);
		getline(cin, C);
		getline(cin, D);
		myFile << question << '\n' << A << '\n' << B << '\n' << C << '\n' << D << '\n';
		cout << "Please, enter correct answer of the question: ";
		getline(cin, correctAns);
		myFile << correctAns << '\n';
		myFile << level << '\n';
		cout << "Enter a category of the question: ";
		getline(cin, category);
		myFile << category << '\n';

		myFile.close();
	}
}

void enterQuestion(fstream& myFile, int& level, string& id, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category) {
	cout << "Please enter level of difficulty of the question: ";
	cin >> level;
	string fileName;
	switch (level) {
	case 1:
	case 2:
	case 3:

		fileName = "question1.txt";
		writeQuestion(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, level);

		break;

	case 4:
	case 5:
	case 6:
		fileName = "question2.txt";
		writeQuestion(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, level);
		break;
	case 7:
	case 8:
	case 9:
	case 10:
		fileName = "question3.txt";
		writeQuestion(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, level);
		break;
	}
	return;
}
