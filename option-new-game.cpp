#include <iostream>
#include <iostream>
#include <string>
#include<fstream>
#include "selected-category.h"
#include "jokers.h"
#include "option-new-game.h"
using namespace std;


//Function for option 1,2,3,4,5
int optionNewGame(fstream& myFile, string& fileName, string& id, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, int& reward, int& lost, int option, int& questionNum) {

	string selectedCat = selectedCategory(option);

	string answer;

	if (fileName == "question1.txt") {
		difficultly[0] = 48;
	}
	else if (fileName == "question2.txt") {
		difficultly[0] = 51;
	}
	else if (fileName == "question3.txt") {
		difficultly[0] = 54;
	}


	string reverseDiff = difficultly;
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

			if (myFile.eof()) {
				break;
			}

			if (reverseDiff[0] == '9') {
				if (reverseDiff[0] - difficultly[0] != 8 || category != selectedCat) {
					continue;
				}
			}
			else {
				if (difficultly[0] - reverseDiff[0] != 1 || category != selectedCat) {

					continue;
				}
			}



			questionNum++;
			cout << '\n';
			cout << questionNum << ".";
			cout << question << endl;
			cout << "A) " << A << endl;
			cout << "B) " << B << endl;
			cout << "C) " << C << endl;
			cout << "D) " << D << endl;

			char choice = ' ';
			jokers(correctAns, fileName, choice, question, A, B, C, D, questionNum);

			cout << "Please, enter an answer:  ";
			cin.ignore();
			getline(cin, answer);
			while (answer == "\0") {
				cout << "Incorrect input! Try again: ";
				getline(cin, answer);
			}
			answer[0] = tolower(answer[0]);
			while (answer != "a" && answer != "b" && answer != "c" && answer != "d") {
				cout << "Incorrect input! Try again: ";
				getline(cin, answer);
				answer[0] = tolower(answer[0]);
			}

			if (answer != correctAns) {
				lost = 0;
				return reward;
			}


			if ((difficultly[0] == '1' && difficultly[1] != '0') || difficultly[0] == '2' || difficultly[0] == '3') {
				reward += 100;
			}
			else if (difficultly[0] == '4' || difficultly[0] == '5' || difficultly[0] == '6') {
				reward += 200;
			}
			else if (difficultly[0] == '7' || difficultly[0] == '8' || difficultly[0] == '9' || (difficultly[0] == '1' && difficultly[1] == '0')) {
				reward += 300;
			}

			question.clear();
			A.clear();
			B.clear();
			C.clear();
			D.clear();
			correctAns.clear();
			reverseDiff = difficultly;
			difficultly.clear();



		} while (answer == correctAns || !myFile.eof());
	}
	myFile.clear();
	myFile.close();
	return reward;

}


//Function for option 6
int optionNewGame(fstream& myFile, string& fileName, string& id, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, int& reward, int& lost, int& questionNum) {

	string answer;

	if (fileName == "question1.txt") {
		difficultly[0] = 48;
	}
	else if (fileName == "question2.txt") {
		difficultly[0] = 51;
	}
	else if (fileName == "question3.txt") {
		difficultly[0] = 54;
	}

	string reverseDiff = difficultly;
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

			if (myFile.eof()) {
				break;
			}

			if (reverseDiff[0] == '9') {
				if (reverseDiff[0] - difficultly[0] != 8) {
					continue;
				}
			}
			else {
				if (difficultly[0] - reverseDiff[0] != 1) {

					continue;
				}
			}


			questionNum++;
			cout << '\n';
			cout << questionNum << ".";
			cout << question << endl;
			cout << "A) " << A << endl;
			cout << "B) " << B << endl;
			cout << "C) " << C << endl;
			cout << "D) " << D << endl;

			char choice;
			jokers(correctAns, fileName, choice, question, A, B, C, D, questionNum);

			cout << "Please, enter an answer (a,b,c or d): ";
			cin.ignore();
			getline(cin, answer);
			while (answer == "\0") {
				cout << "Invalid input! Try again: ";
				getline(cin, answer);
			}
			answer[0] = tolower(answer[0]);
			while (answer != "a" && answer != "b" && answer != "c" && answer != "d") {
				cout << "Incorrect input! Try again: ";
				getline(cin, answer);
				answer[0] = tolower(answer[0]);
			}


			if (answer != correctAns) {
				lost = 0;
				return reward;
			}

			if ((difficultly[0] == '1' && difficultly[1] != '0') || difficultly[0] == '2' || difficultly[0] == '3') {
				reward += 100;
			}
			else if (difficultly[0] == '4' || difficultly[0] == '5' || difficultly[0] == '6') {
				reward += 200;
			}
			else if (difficultly[0] == '7' || difficultly[0] == '8' || difficultly[0] == '9' || (difficultly[0] == '1' && difficultly[1] == '0')) {
				reward += 300;
			}

			question.clear();
			A.clear();
			B.clear();
			C.clear();
			D.clear();
			correctAns.clear();
			reverseDiff = difficultly;
			difficultly.clear();



		} while (answer == correctAns || !myFile.eof());
	}
	myFile.clear();
	myFile.close();
	return reward;
}