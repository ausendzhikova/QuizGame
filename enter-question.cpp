#include<iostream>
#include<fstream>
#include<string>
#include "transform-validation.h"
using namespace std;

#include "enter-question.h"

string readFile(fstream& myFile, string& fileName, string& id, string& question, string& A,
	string& B, string& C, string& D, string& correctAns, string& difficultly, string& category) {
	myFile.open(fileName, fstream::in);
	if (!myFile.is_open()) {
		cout << "File doesn't open" << endl;
	}
	else {
		myFile.seekp(0);
		while (!myFile.eof()) {
			getline(myFile, id);
			getline(myFile, question);
			getline(myFile, A);
			getline(myFile, B);
			getline(myFile, C);
			getline(myFile, D);
			getline(myFile, correctAns);
			getline(myFile, difficultly);
			getline(myFile, category);

		}
	}
	myFile.close();
	return id;
}

void writeQuestion(fstream& myFile, string& fileName, string& id, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, string level) {
	string idNumb = readFile(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category);
	char newId[4];

	newId[0] = idNumb[0];
	newId[1] = idNumb[1] + 1;
	if (idNumb[0] == '9' && idNumb[1] == '9') {
		newId[0] = '1';
		newId[1] = '0';
		newId[2] = '0';
	}

	if (idNumb[1] == '9') {
		newId[0] = idNumb[0] + 1;
		newId[1] = '0';
	}

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

		if (newId[0] == '1' && newId[1] == '0' && newId[2] == '0') {
			myFile << '\n' << newId[0] << newId[1] << newId[2] << "-id\n";
		}
		else {
			myFile << '\n' << newId[0] << newId[1] << "-id\n";
		}


		cout << "Enter a question: ";

		getline(cin, question);
		isEmpty(question);
		cout << "Enter first answer: ";
		getline(cin, A);
		isEmpty(A);
		cout << "Enter second answer: ";
		getline(cin, B);
		isEmpty(B);
		cout << "Enter third answer: ";
		getline(cin, C);
		isEmpty(C);
		cout << "Enter fourth answer: ";
		getline(cin, D);
		isEmpty(D);
		myFile << question << '\n' << A << '\n' << B << '\n' << C << '\n' << D << '\n';
		cout << "Please, enter correct answer of the question: ";
		getline(cin, correctAns);
		isEmpty(correctAns);
		transformStr(correctAns);
		while (correctAns != "a" && correctAns != "b" && correctAns != "c" && correctAns != "d") {
			cout << "Invalid input! Try again: ";
			getline(cin, correctAns);
			transformStr(correctAns);
		}


		myFile << correctAns << '\n';
		myFile << level << '\n';
		cout << "Enter a category of the question: ";
		getline(cin, category);
		while (category == "\0") {
			cout << "Invalid input! Try again: ";
			getline(cin, category);
		}
		category[0] = toupper(category[0]);
		for (size_t i = 1; i < category.size(); i++) {
			category[i] = tolower(category[i]);
		}
		myFile << category;

		myFile.close();
	}
}

void enterQuestion(fstream& myFile, string level, string& id, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category) {

	cin.ignore();
	cout << "Please enter level of difficulty of the question: ";
	getline(cin, level);

	//Validation
	isEmpty(level);
	while (level != "1" && level != "2" && level != "3" && level != "4" && level != "5" && level != "6" && level != "7" && level != "8" && level != "9" && level != "10") {
		cout << "Inavlid input! Try again: ";
		getline(cin, level);
	}


	string fileName;
	if (level == "1" || level == "2" || level == "3") {
		fileName = "question1.txt";
		writeQuestion(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, level);
		return;
	}
	if (level == "4" || level == "5" || level == "6") {
		fileName = "question2.txt";
		writeQuestion(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, level);
		return;
	}
	if (level == "7" || level == "8" || level == "9" || level == "10") {
		fileName = "question3.txt";
		writeQuestion(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, level);
		return;
	}
}