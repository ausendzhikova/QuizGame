#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
#include <cstdlib>
#include "Random.h"

using namespace std;

void printAfterJoker(string& question, string& A, string& B, string& C, string& D, char& randChar, char& randChar2, int& questionNum) {
	cout << '\n';
	cout << questionNum << '.';
	cout << question << endl;
	if ((randChar == 'a' || randChar2 == 'a') && (randChar == 'b' || randChar2 == 'b')) {
		cout << '\n';
		cout << '\n';
		cout << C << endl;
		cout << D << endl;
	}
	else if ((randChar == 'a' || randChar2 == 'a') && (randChar == 'c' || randChar2 == 'c')) {
		cout << '\n';
		cout << B << endl;
		cout << '\n';
		cout << D << endl;
	}
	else if ((randChar == 'a' || randChar2 == 'a') && (randChar == 'd' || randChar2 == 'd')) {
		cout << '\n';
		cout << B << endl;
		cout << C << endl;
		cout << '\n';

	}
	else if ((randChar == 'b' || randChar2 == 'b') && (randChar == 'c' || randChar2 == 'c')) {
		cout << A << endl;
		cout << '\n';
		cout << '\n';
		cout << D << endl;
	}
	else if ((randChar == 'b' || randChar2 == 'b') && (randChar == 'd' || randChar2 == 'd')) {
		cout << A << endl;
		cout << '\n';
		cout << C << endl;
		cout << '\n';
	}
	else if ((randChar == 'c' || randChar2 == 'c') && (randChar == 'd' || randChar2 == 'd')) {
		cout << A << endl;
		cout << B << endl;
		cout << '\n';
		cout << '\n';
	}

	return;
}

bool x_isUsed = false;
bool y_isUsed = false;
bool z_isUsed = false;

string wantToUseJoker(bool& x_isUsed, bool& y_isUsed, bool& z_isUsed,string &YesOrNo) {

	if (!x_isUsed && !y_isUsed && !z_isUsed) {
		cout << "You can use jokers: 50/50 , help from the audience, call to friend." << endl;
		cout << "Are you want to use some of them? (yes or no): ";
		
	}

	if (x_isUsed && !y_isUsed && !z_isUsed) {
		cout << "You can use jokers: help from the audience, call to friend. " << endl;
		cout << "Are you want to use some of them? (yes or no): ";
		
	}

	if (!x_isUsed && y_isUsed && !z_isUsed) {
		cout << "You can use jokers: 50/50, call to friend. " << endl;
		cout << "Are you want to use some of them? (yes or no): ";
		
	}

	if (!x_isUsed && !y_isUsed && z_isUsed) {
		cout << "You can use jokers: 50/50, help from the audience. " << endl;
		cout << "Are you want to use some of them? (yes or no): ";
		
	}

	if (x_isUsed && y_isUsed && !z_isUsed) {
		cout << "You can use joker: call to friend." << endl;
		cout << "Are you want to use it? (yes or no): ";
	
	}

	if (x_isUsed && !y_isUsed && z_isUsed) {
		cout << "You can use joker: help from the audience." << endl;
		cout << "Are you want to use it? (yes or no): ";
		
	}

	if (!x_isUsed && y_isUsed && z_isUsed) {
		cout << "You can use joker: 50/50." << endl;
		cout << "Are you want to use it? (yes or no): ";
		
	}
	
	if (x_isUsed && y_isUsed && z_isUsed) {
		YesOrNo = "no";
		return YesOrNo;
	}

	cin >> YesOrNo;
	transform(YesOrNo.begin(), YesOrNo.end(), YesOrNo.begin(), ::tolower);
	while (YesOrNo != "yes" && YesOrNo != "no") {
		cout << "Incorret input! Try again: ";
		cin >> YesOrNo;
		transform(YesOrNo.begin(), YesOrNo.end(), YesOrNo.begin(), ::tolower);
	}

	return YesOrNo;
}

void choiceForJoker(char &choice) {
	if (!x_isUsed && !y_isUsed && !z_isUsed) {
		cout << "Enter your choice (X - 50/50; Y- help from the audience; Z- call to friend; 0 - Exit): ";
		cin >> choice;
		choice = toupper(choice);
		while (choice != 'X' && choice != 'Y' && choice != 'Z' && choice != '0') {
			cout << "Incorrect input! Try again: ";
			cin >> choice;
			choice = toupper(choice);
		}
	}

	if (x_isUsed && !y_isUsed && !z_isUsed) {
		cout << "Enter your choice (Y- help from the audience; Z- call to friend; 0 - Exit): ";
		cin >> choice;
		choice = toupper(choice);
		while (choice != 'Y' && choice != 'Z' && choice != '0') {
			cout << "Incorrect input! Try again: ";
			cin >> choice;
			choice = toupper(choice);
		}
	}

	if (!x_isUsed && y_isUsed && !z_isUsed) {
		cout << "Enter your choice (X - 50/50; Z- call to friend; 0 - Exit): ";
		cin >> choice;
		choice = toupper(choice);
		while (choice != 'X' && choice != 'Z' && choice != '0') {
			cout << "Incorrect input! Try again: ";
			cin >> choice;
			choice = toupper(choice);
		}
	}

	if (!x_isUsed && !y_isUsed && z_isUsed) {
		cout << "Enter your choice (X - 50/50; Y- help from the audience; 0 - Exit): ";
		cin >> choice;
		choice = toupper(choice);
		while (choice != 'X' && choice != 'Y' &&  choice != '0') {
			cout << "Incorrect input! Try again: ";
			cin >> choice;
			choice = toupper(choice);
		}
	}

	if (x_isUsed && y_isUsed && !z_isUsed) {
		cout << "Enter your choice (Z- call to friend; 0 - Exit): ";
		cin >> choice;
		choice = toupper(choice);
		while (choice != 'Z' && choice != '0') {
			cout << "Incorrect input! Try again: ";
			cin >> choice;
			choice = toupper(choice);
		}
	}

	if (x_isUsed && !y_isUsed && z_isUsed) {
		cout << "Enter your choice (Y- help from the audience; 0 - Exit): ";
		cin >> choice;
		choice = toupper(choice);
		while (choice != 'Y' && choice != '0') {
			cout << "Incorrect input! Try again: ";
			cin >> choice;
			choice = toupper(choice);
		}
	}

	if (!x_isUsed && y_isUsed && z_isUsed) {
		cout << "Enter your choice (X - 50/50; 0 - Exit): ";
		cin >> choice;
		choice = toupper(choice);
		while (choice != 'X' && choice != '0') {
			cout << "Incorrect input! Try again: ";
			cin >> choice;
			choice = toupper(choice);
		}
	}
}

void jokers(string& correctAns, string& fileName, char& choice, string& question, string& A, string& B, string& C, string& D, int& questionNum) {

	string YesOrNo;

	YesOrNo=wantToUseJoker(x_isUsed, y_isUsed, z_isUsed,YesOrNo);

	if (YesOrNo == "yes") {

		choiceForJoker(choice);

		char guessAns;
		int randNum = 0;
		char randChar = ' ';
		char randChar2 = ' ';

		switch (choice) {
		case 'X':
			x_isUsed = true;
			random(correctAns, randNum, randChar, randChar2);
			printAfterJoker(question, A, B, C, D, randChar, randChar2, questionNum);
			break;

		case 'Y':
			y_isUsed = true;
			guessAns = randomWithProbability(correctAns, fileName, randNum, randChar);

			cout << "Maybe answer is: " << guessAns << endl;
			break;

		case 'Z':
			z_isUsed = true;
			guessAns = randomWithProbability(correctAns, fileName, randNum, randChar);
			cout << "I think the answer is: " << guessAns << endl;
			break;
		default:
			break;
		}
	}

	return;
}
