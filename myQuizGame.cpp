#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include "OptionNewGame.h"
#include "enterQuestion.h"
#include "editQuestion.h"
using namespace std;




int main() {

	cout << "\n\t\t **********************  Became Rich **********************";
	cout << "\n\t\t **                                                      **";
	cout << "\n\t\t **                      > 1.New Game <                  **";
	cout << "\n\t\t **                > 2. Enter a new question <           **";
	cout << "\n\t\t **                   > 3. Edit question <               **";
	cout << "\n\t\t **                       > 4. Exit <                    **";
	cout << "\n\t\t **                                                      **";
	cout << "\n\t\t **********************************************************";
	cout << "\n\n";

	int option;
	cout << "Please select an option (1-4): ";
	cin >> option;
	while (option < 1 || option>4) {
		cout << "Incorrect input! Try again: ";
		cin >> option;
	}

	fstream myFile;
	string id;
	string A, B, C, D;
	string question;
	string correctAns;
	string difficultly;
	string category;
	string fileName;

	if (option == 1) {

		char answer;
		int reward = 0;
		int lost = 1;
		int questionNum = 0;


		cout << "\n";
		cout << "\n";
		cout << "\t    1.Math           \n";
		cout << "\t    2.Geopgraphy     \n";
		cout << "\t    3.History        \n";
		cout << "\t    4.Physics        \n";
		cout << "\t    5.Chemistry      \n";
		cout << "\t    6.All category   \n";
		cout << "Please select a category (1-6): ";

		cin >> option;
		while (option < 1 || option>6) {
			cout << "Incorrect input! Try again: ";
			cin >> option;
		}

		fileName = "question1.txt";

		if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5) {
			optionNewGame(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, reward, lost, option, questionNum);

			if (lost == 0) {
				cout << "Wrong answer! The correct answer is:  "<<correctAns[0] << endl;
				if (reward == 0) {
					cout << "\t\tGame over! ";
				}
				else {
					cout << "\n\t\tGame over!\n\tCongratulations! You win " << reward << "$." << endl;
				}
				return 0;
			}

			fileName = "question2.txt";
			optionNewGame(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, reward, lost, option, questionNum);
			if (lost == 0) {
				cout << "Wrong answer! The correct answer is:  " << correctAns[0] << endl;
				cout << "\n\t\tGame over!\n\tCongratulations! You win " << reward << "$." << endl;
				return 0;
			}

			fileName = "question3.txt";
			optionNewGame(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, reward, lost, option, questionNum);

			if (lost == 0) {
				cout << "Wrong answer! The correct answer is:  " << correctAns[0] << endl;
			}
			cout << "\n\t\tGame over!\n\tCongratulations! You win " << reward << "$." << endl;

		}

		else if (option == 6) {

			optionNewGame(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, reward, lost, questionNum);
			if (lost == 0) {
				cout << "Wrong answer! The correct answer is:  " << correctAns[0] << endl;
				if (reward == 0) {
					cout << "\t\tGame over! ";
				}
				else {

					cout << "\n\t\tGame over!\n\tCongratulations! You win " << reward << "$." << endl;
				}
				return 0;
			}

			fileName = "question2.txt";
			optionNewGame(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, reward, lost, questionNum);
			if (lost == 0) {
				cout << "Wrong answer! The correct answer is:  " << correctAns[0] << endl;
				cout << "\n\t\tGame over!\n\tCongratulations! You won " << reward << "$." << endl;
				return 0;
			}

			fileName = "question3.txt";
			optionNewGame(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, reward, lost, questionNum);
			if (lost == 0) {
				cout << "Wrong answer! The correct answer is:  " << correctAns[0] << endl;
			}
			cout << "\n\t\tGame over!\n\tCongratulations! You win " << reward << "$." << endl;

		}
	}
	else if (option == 2) {

		int level = 0;
		enterQuestion(myFile, level, id, question, A, B, C, D, correctAns, difficultly, category);
	}
	else if (option == 3) {
		bool isNotFound = true;
		int level = 0;

		editQuestion(level, fileName, id, question, A, B, C, D, correctAns, difficultly, category, isNotFound);

		while (isNotFound) {
			cout << "\nQuestion with this id doesn't exist. Try again!" << endl;
			cout << '\n';
			editQuestion(level, fileName, id, question, A, B, C, D, correctAns, difficultly, category, isNotFound);
		}
	}
	else if (option == 4) {
		cout << "\n\t\tGoodbye!" << endl;
	}

	return 0;
}