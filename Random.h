#pragma once
#include <iostream>
#include <string>
#include<vector>

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