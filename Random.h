#pragma once
using namespace std;

char randomWithProbability(string& correctAns, string& fileName, int& randNum, char& randChar);
void random(string& correctAns, int& randNum, char& randChar, char& randChar2);
void printCorrectAns(string& fileName, int& randNum, string& correctAns);
void isDiffValid(int& difference, int& randNum_X);
void publicAnsPercent(string& fileName, int& randNum, string& correctAns);