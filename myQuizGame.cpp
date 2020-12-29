#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "OptionNewGame.h"
#include "enterQuestion.h"
using namespace std;




int main() {

	cout << "\n\t\t **********************  BecameRich  **********************";
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

	if (option == 1) {

		//Variable
		fstream myFile;
		string id;
		string A, B, C, D;
		string question;
		char answer;
		string correctAns;
		string difficultly;
		string category;
		int reward = 0;
		int lost = 1;
		int questionNum = 0;
		string fileName = "question1.txt";

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

		if (option == 1 || option==2 || option==3 || option==4 || option==5) {
			optionNewGame(myFile,fileName,id, question, A, B, C, D, correctAns, difficultly, category, reward, lost, option, questionNum);

			if (lost == 0) {
				cout << "Wrong answer! " << endl;
				if (reward == 0) {
					cout << "\t\tGame over! ";
				}
				else {
					cout << "\n\t\tGame over!\n\tCongratulations! You win " << reward << "$." << endl;
				}
				return 0;
			}

			fileName = "question2.txt";
			optionNewGame(myFile, fileName, id, question, A, B, C, D, correctAns, difficultly, category, reward,lost, option, questionNum);
			if (lost == 0) {
				cout << "Wrong answer! " << endl;
				cout << "\n\t\tGame over!\n\tCongratulations! You win " << reward << "$." << endl;
				return 0;
			}

			fileName = "question3.txt";
			optionNewGame(myFile,fileName,id, question, A, B, C, D, correctAns, difficultly, category, reward,lost, option, questionNum);

			if (lost == 0) {
				cout << "Wrong answer! " << endl;
			}
			cout << "\n\t\tGame over!\n\tCongratulations! You win " << reward << "$." << endl;

		}
		
		else if (option == 6) {

			optionNewGame(myFile,fileName,id, question, A, B, C, D, correctAns, difficultly, category, reward, lost, questionNum);
			if (lost == 0) {
				cout << "Wrong answer!" << endl;
				if (reward == 0) {
					cout << "\t\tGame over! ";
				}
				else {

					cout << "\n\t\tGame over!\n\tCongratulations! You win " << reward << "$." << endl;
				}
				return 0;
			}

			fileName = "question2.txt";
			optionNewGame(myFile,fileName,id, question, A, B, C, D, correctAns, difficultly, category, reward, lost, questionNum);
			if (lost == 0) {
				cout << "Wrong answer! " << endl;
				cout << "\n\t\tGame over!\n\tCongratulations! You won " << reward << "$." << endl;
				return 0;
			}

			fileName = "question3.txt";
			optionNewGame(myFile,fileName,id, question, A, B, C, D, correctAns, difficultly, category, reward,lost, questionNum);
			if (lost == 0) {
				cout << "Wrong answer! " << endl;
			}
			cout << "\n\t\tGame over!\n\tCongratulations! You win " << reward << "$." << endl;

		}
	}
	else if (option == 2) {

	}
	else if (option == 3) {
		//Variable
		fstream myFile;
		string id;
		string A, B, C, D;
		string question;
		int questions;
		char answer;
		string correctAns;
		string difficultly;
		string category;
		int reward = 0;
		int lost = 1;
		int questionNum = 0;


		int level=0;
		enterQuestion(myFile, level, id, question, A, B, C, D, correctAns, difficultly, category);

	}
	else if (option == 4) {
		cout << "Goodbye" << endl;
	}



	return 0;
}












/*void Jokers(string &correctAns) {
	//Jokers
	string joker;
	cout << "You can use jokers: 50/50 , help from the audience, call to friend." << endl;
	cout << "Are you want to use some of them? (yes or no): ";
	cin >> joker;
	transform(joker.begin(), joker.end(), joker.begin(), ::tolower);
	while (joker != "yes" || joker != "no") {
		cout << "Invalid input! try again: ";
		cin >> joker;
		transform(joker.begin(), joker.end(), joker.begin(), ::tolower);
	}

	if (joker == "yes") {
		int choice;
		cout << "Enter your choice (1 - 50/50; 2- help from the audience; 3- call to frien; 0 - Exit): ";
		cin >> choice;
		while (choice != 0 || choice != 1 || choice != 2 || choice != 3) {
			cout << "Invalid input! Try again: ";
			cin >> choice;
		}
		switch (choice) {
		case 1:
			if (correctAns[0] == 'a') {
				cout << "Answers b and c are eliminated. Choose a or b: ";
			}
			else if (correctAns[0] == 'b') {
				cout << "Answers a and d are eliminated. Choose b or c: ";
			}
			else if (correctAns[0] == 'c') {
				cout << "Answers b and d are eliminated. Choose a or c:  ";
			}
			else if (correctAns[0] == 'd') {
				cout << "Answers a and c are eliminated. Choose b or d: ";
			}
			break;
		case 2:

		}

	}
}*/
