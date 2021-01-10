#include <iostream>
#include <string>
#include<vector>
#include "random.h"

using namespace std;

char randomWithProbability(string& correctAns, string& fileName, int& randNum, char& randChar) {

	srand((unsigned)time(0));
	randNum = rand() % 100 + 1;

	if (fileName == "question1.txt" && randNum <= 70) {
		return correctAns[0];
	}
	else if (fileName == "question2.txt" && randNum <= 40) {
		return correctAns[0];
	}
	else if (fileName == "question3.txt" && randNum <= 20) {
		return correctAns[0];
	}

	srand((unsigned)time(0));
	randNum = rand() % 4 + 1;
	randChar = 96 + randNum;
	while (randChar == correctAns[0]) {
		srand((unsigned)time(0));
		randNum = rand() % 4 + 1;
		randChar = 96 + randNum;
	}
	return randChar;
}

void random(string& correctAns, int& randNum, char& randChar, char& randChar2) {

	srand((unsigned)time(0));
	for (int i = 0; i < 2; i++) {
		randChar2 = randChar;
		randNum = rand() % 4 + 1;
		randChar = 96 + randNum;
		if (randChar == correctAns[0] || randChar2 == correctAns[0] || randChar2 == randChar) {
			i--;
		}
	}

	return;
}

void printCorrectAns(string& fileName, int& randNum, string& correctAns) {
	correctAns[0] = toupper(correctAns[0]);
	if (fileName == "question1.txt" && randNum <= 70) {
		cout << correctAns[0] << ") " << randNum << "%   ";
	}
	else if (fileName == "question2.txt" && randNum <= 40) {
		cout << correctAns[0] << ") " << randNum << "%   ";
	}
	else if (fileName == "question3.txt" && randNum <= 20) {
		cout << correctAns[0] << ") " << randNum << "%   ";
	}
	else {
		cout << correctAns[0] << ") " << randNum << "%   ";
	}
		correctAns[0] = tolower(correctAns[0]);
		return;
	}

	void isDiffValid(int& difference, int& randNum_X) {
		if (difference != 0) {
			randNum_X = rand() % difference + 1;
		}
		else {
			randNum_X = 0;
		}
	}

	void publicAnsPercent(string & fileName, int& randNum, string & correctAns) {
		int randNum_A = 0, randNum_B = 0, randNum_C = 0, randNum_D = 0;
		srand((unsigned)time(0));
		randNum = rand() % 100 + 1;


		int difference = 100 - randNum;
		switch (correctAns[0]) {
		case 'a':
			printCorrectAns(fileName, randNum, correctAns);
			randNum_B = rand() % difference + 1;
			cout << "B) " << randNum_B << "%   ";
			difference -= randNum_B;
			isDiffValid(difference, randNum_C);
			cout << "C) " << randNum_C << "%   ";
			difference -= randNum_C;
			cout << "D) " << difference << "%   ";
			cout << '\n';
			return;

		case 'b':
			randNum_A = rand() % difference + 1;
			cout << "A) " << randNum_A << "%   ";
			printCorrectAns(fileName, randNum, correctAns);
			difference -= randNum_A;
			isDiffValid(difference, randNum_C);
			cout << "C) " << randNum_C << "%   ";
			difference -= randNum_C;
			cout << "D) " << difference << "%   ";
			cout << '\n';
			return;
		case 'c':
			randNum_A = rand() % difference + 1;
			cout << "A) " << randNum_A << "%   ";
			difference -= randNum_A;
			isDiffValid(difference, randNum_B);
			cout << "B) " << randNum_B << "%   ";
			printCorrectAns(fileName, randNum, correctAns);
			difference -= randNum_B;
			cout << "D) " << difference << "%   ";
			cout << '\n';
			return;
		case 'd':
			randNum_A = rand() % difference + 1;
			cout << "A) " << randNum_A << "%   ";
			difference -= randNum_A;
			isDiffValid(difference, randNum_B);
			cout << "B) " << randNum_B << "%   ";
			difference -= randNum_B;
			cout << "C) " << difference << "%   ";
			printCorrectAns(fileName, randNum, correctAns);
			cout << '\n';
			return;
		}


	}