#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int firstDiffCategory(ifstream&, string&, string&, string&, string&, string&, string&, string&, string&, int&, int&, int&);
int secondDiffCategory(ifstream&, string&, string&, string&, string&, string&, string&, string&, string&, int&, int&, int&);
int thirdDiffCategory(ifstream&, string&, string&, string&, string&, string&, string&, string&, string&, int&, int&);

int firstDiffCategory(ifstream&, string&, string&, string&, string&, string&, string&, string&, string&, int&, int&, int, int&);
int secondDiffCategory(ifstream&, string&, string&, string&, string&, string&, string&, string&, string&, int&, int&, int, int&);
int thirdDiffCategory(ifstream&, string&, string&, string&, string&, string&, string&, string&, string&, int&, int, int&);
string selectedCategory(int);




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
		cout << "\n";
		cout << "\n";
		cout << "\t    1.Math           \n";
		cout << "\t    2.Geopgraphy     \n";
		cout << "\t    3.History        \n";
		cout << "\t    4.Physics        \n";
		cout << "\t    5.Chemistry      \n";
		cout << "\t    6.All category   \n";
		cout << "Please select a category (1-6): ";

		int option;
		cin >> option;
		while (option < 1 || option>6) {
			cout << "Incorrect input! Try again: ";
			cin >> option;
		}

		//Variable
		ifstream myFile;
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

		if (option == 1) {
			firstDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, 1, questionNum);

			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}
			secondDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, 1, questionNum);
			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}

			thirdDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, 1, questionNum);

			cout << "Congratulations! You won " << reward << "$." << endl;


		}
		else if (option == 2) {

			firstDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, 2, questionNum);

			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}
			secondDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, 2, questionNum);
			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}

			thirdDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, 2, questionNum);

			cout << "Congratulations! You won " << reward << "$." << endl;
		}
		else if (option == 3) {
			firstDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, 3, questionNum);

			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}
			secondDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, 3, questionNum);
			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}

			thirdDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, 3, questionNum);

			cout << "Congratulations! You won " << reward << "$." << endl;
		}
		else if (option == 4) {
			firstDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, 4, questionNum);

			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}
			secondDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, 4, questionNum);
			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}

			thirdDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, 4, questionNum);

			cout << "Congratulations! You won " << reward << "$." << endl;
		}
		else if (option == 5) {
			firstDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, 5, questionNum);

			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}
			secondDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, 5, questionNum);
			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}

			thirdDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, 5, questionNum);

			cout << "Congratulations! You won " << reward << "$." << endl;
		}
		else if (option == 6) {
			firstDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, questionNum);

			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}
			secondDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, lost, questionNum);
			if (lost == 0) {
				cout << "Congratulations! You won " << reward << "$." << endl;
				return 0;
			}

			thirdDiffCategory(myFile, question, A, B, C, D, correctAns, difficultly, category, reward, questionNum);

			cout << "Congratulations! You won " << reward << "$." << endl;
		}
	}
	else if (option == 2) {

	}
	else if (option == 3) {

	}
	else if (option == 4) {
		cout << "Goodbye" << endl;
	}



	return 0;
}


//Function for option1,2,3,4,5
int firstDiffCategory(ifstream& myFile, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, int& reward, int& lost, int option, int& questionNum) {

	string selectedCat = selectedCategory(option);

	char answer = ' ';
	difficultly[0] = 48;
	char reverseDiff = difficultly[0];
	myFile.open("question1.txt");
	if (!myFile.is_open()) {
		cout << "File doesn't open" << endl;
	}
	else {

		do {
			getline(myFile, question);
			getline(myFile, A);
			getline(myFile, B);
			getline(myFile, C);
			getline(myFile, D);
			getline(myFile, correctAns);
			getline(myFile, difficultly);
			getline(myFile, category);

			if (difficultly[0] - reverseDiff != 1 || category != selectedCat) {

				continue;
			}

			questionNum++;
			cout << questionNum << ".";
			cout << question << endl;
			cout << A << endl;
			cout << B << endl;
			cout << C << endl;
			cout << D << endl;
			cin >> answer;
			cout << '\n';

			if (answer != correctAns[0]) {
				lost = 0;
				return reward;
			}
			reward += 100;

			question.clear();
			A.clear();
			B.clear();
			C.clear();
			D.clear();
			correctAns.clear();
			reverseDiff = difficultly[0];
			difficultly.clear();

		} while (answer == correctAns[0] || !myFile.eof());

	}
	myFile.clear();
	myFile.close();
	return reward;
}

int secondDiffCategory(ifstream& myFile, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, int& reward, int& lost, int option, int& questionNum) {

	string selectedCat = selectedCategory(option);

	char answer = ' ';
	difficultly[0] = 51;
	char reverseDiff = difficultly[0];
	myFile.open("question2.txt");
	if (!myFile.is_open()) {
		cout << "File doesn't open" << endl;
	}
	else {

		do {
			getline(myFile, question);
			getline(myFile, A);
			getline(myFile, B);
			getline(myFile, C);
			getline(myFile, D);
			getline(myFile, correctAns);
			getline(myFile, difficultly);
			getline(myFile, category);

			if (difficultly[0] - reverseDiff != 1 || category != selectedCat) {

				continue;
			}

			questionNum++;
			cout << questionNum << ".";
			cout << question << endl;
			cout << A << endl;
			cout << B << endl;
			cout << C << endl;
			cout << D << endl;
			cin >> answer;
			cout << '\n';

			if (answer != correctAns[0]) {
				lost = 0;
				return reward;
			}
			reward += 100;

			question.clear();
			A.clear();
			B.clear();
			C.clear();
			D.clear();
			correctAns.clear();
			reverseDiff = difficultly[0];
			difficultly.clear();



		} while (answer == correctAns[0] || !myFile.eof());
	}
	myFile.clear();
	myFile.close();
	return reward;

}

int thirdDiffCategory(ifstream& myFile, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, int& reward, int option, int& questionNum) {

	string selectedCat = selectedCategory(option);

	char answer = ' ';
	difficultly[0] = 54;
	char reverseDiff = difficultly[0];
	myFile.open("question3.txt");
	if (!myFile.is_open()) {
		cout << "File doesn't open" << endl;
	}
	else {

		do {
			getline(myFile, question);
			getline(myFile, A);
			getline(myFile, B);
			getline(myFile, C);
			getline(myFile, D);
			getline(myFile, correctAns);
			getline(myFile, difficultly);
			getline(myFile, category);

			if (difficultly[0] - reverseDiff != 1 || category != selectedCat) {

				continue;
			}

			questionNum++;
			cout << questionNum << ".";
			cout << question << endl;
			cout << A << endl;
			cout << B << endl;
			cout << C << endl;
			cout << D << endl;
			cin >> answer;
			cout << '\n';

			if (answer != correctAns[0]) {
				return reward;
			}
			reward += 100;

			question.clear();
			A.clear();
			B.clear();
			C.clear();
			D.clear();
			correctAns.clear();
			reverseDiff = difficultly[0];
			difficultly.clear();

		} while (answer == correctAns[0] || !myFile.eof());
	}
	myFile.clear();
	myFile.close();
	return reward;

}

string selectedCategory(int option) {
	string selectedCat;
	switch (option) {
	case 1:
		selectedCat = "Math";
		break;
	case 2:
		selectedCat = "Geography";
		break;
	case 3:
		selectedCat = "History";
		break;
	case 4:
		selectedCat = "Physics";
		break;
	case 5:
		selectedCat = "Chemistry";
		break;
	}

	return selectedCat;
}


//Funkction for option 6
int firstDiffCategory(ifstream& myFile, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, int& reward, int& lost, int& questionNum) {

	char answer = ' ';
	difficultly[0] = 48;
	char reverseDiff = difficultly[0];



	myFile.open("question1.txt");
	if (!myFile.is_open()) {
		cout << "File doesn't open" << endl;
	}
	else {

		do {
			getline(myFile, question);
			getline(myFile, A);
			getline(myFile, B);
			getline(myFile, C);
			getline(myFile, D);
			getline(myFile, correctAns);
			getline(myFile, difficultly);
			getline(myFile, category);

			if (difficultly[0] - reverseDiff != 1) {

				continue;
			}
			questionNum++;
			cout << questionNum << ".";
			cout << question << endl;
			cout << A << endl;
			cout << B << endl;
			cout << C << endl;
			cout << D << endl;
			cin >> answer;
			cout << '\n';

			if (answer != correctAns[0]) {
				lost = 0;
				return reward;
			}
			reward += 100;

			question.clear();
			A.clear();
			B.clear();
			C.clear();
			D.clear();
			correctAns.clear();
			reverseDiff = difficultly[0];
			difficultly.clear();

		} while (answer == correctAns[0] || !myFile.eof());

	}
	myFile.clear();
	myFile.close();
	return reward;
}

int secondDiffCategory(ifstream& myFile, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, int& reward, int& lost, int& questionNum) {

	char answer = ' ';
	difficultly[0] = 51;
	char reverseDiff = difficultly[0];
	myFile.open("question2.txt");
	if (!myFile.is_open()) {
		cout << "File doesn't open" << endl;
	}
	else {

		do {
			getline(myFile, question);
			getline(myFile, A);
			getline(myFile, B);
			getline(myFile, C);
			getline(myFile, D);
			getline(myFile, correctAns);
			getline(myFile, difficultly);
			getline(myFile, category);

			if (difficultly[0] - reverseDiff != 1) {

				continue;
			}
			questionNum++;
			cout << questionNum << ".";
			cout << question << endl;
			cout << A << endl;
			cout << B << endl;
			cout << C << endl;
			cout << D << endl;
			cin >> answer;
			cout << '\n';

			if (answer != correctAns[0]) {
				lost = 0;
				return reward;
			}
			reward += 100;

			question.clear();
			A.clear();
			B.clear();
			C.clear();
			D.clear();
			correctAns.clear();
			reverseDiff = difficultly[0];
			difficultly.clear();



		} while (answer == correctAns[0] || !myFile.eof());
	}
	myFile.clear();
	myFile.close();
	return reward;

}

int thirdDiffCategory(ifstream& myFile, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, int& reward, int& questionNum) {

	char answer = ' ';
	difficultly[0] = 54;
	char reverseDiff = difficultly[0];
	myFile.open("question3.txt");
	if (!myFile.is_open()) {
		cout << "File doesn't open" << endl;
	}
	else {

		do {
			getline(myFile, question);
			getline(myFile, A);
			getline(myFile, B);
			getline(myFile, C);
			getline(myFile, D);
			getline(myFile, correctAns);
			getline(myFile, difficultly);
			getline(myFile, category);

			if (difficultly[0] - reverseDiff != 1) {

				continue;
			}

			questionNum++;
			cout << questionNum << ".";
			cout << question << endl;
			cout << A << endl;
			cout << B << endl;
			cout << C << endl;
			cout << D << endl;
			cin >> answer;
			cout << '\n';

			if (answer != correctAns[0]) {
				return reward;
			}
			reward += 100;

			question.clear();
			A.clear();
			B.clear();
			C.clear();
			D.clear();
			correctAns.clear();
			reverseDiff = difficultly[0];
			difficultly.clear();

		} while (answer == correctAns[0] || !myFile.eof());
	}
	myFile.clear();
	myFile.close();
	return reward;

}


