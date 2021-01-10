#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string readFile(fstream& myFile, string& fileName, string& id, string& question, string& A,string& B, string& C, string& D, string& correctAns, string& difficultly, string& category);
void writeQuestion(fstream& myFile, string& fileName, string& id, string& question, string& A, string& B, string& C, string& D,string& correctAns, string& difficultly, string& category, string level);
void enterQuestion(fstream& myFile, string level, string& id, string& question, string& A, string& B, string& C, string& D, string& correctAns, string& difficultly, string& category);