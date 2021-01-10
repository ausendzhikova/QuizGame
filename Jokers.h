#pragma once
using namespace std;

void printAfterJoker(string& question, string& A, string& B, string& C, string& D, char& randChar, char& randChar2, int& questionNum);
string wantToUseJoker(bool& x_isUsed, bool& y_isUsed, bool& z_isUsed, string& YesOrNo);
void choiceForJoker(char& choice);
void jokers(string& correctAns, string& fileName, char& choice, string& question, string& A, string& B, string& C, string& D, int& questionNum);

