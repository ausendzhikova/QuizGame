#pragma once
#include <string>
using namespace std;

//Function for option 1,2,3,4,5
int optionNewGame(fstream& myFile, string& fileName, string& id, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, int& reward, int& lost, int option, int& questionNum);
//Function for option 6
int optionNewGame(fstream& myFile, string& fileName, string& id, string& question, string& A, string& B, string& C, string& D,
	string& correctAns, string& difficultly, string& category, int& reward, int& lost, int& questionNum);