#include <iostream>
#include <string>
#include "transform-validation.h"
using namespace std;

//transform
void transformStr(string& newData) {
	for (size_t i = 0; i < newData.size(); ++i) {
		newData[i] = tolower(newData[i]);
	}
	return;
}

void transformCat(string& newData, int n) {
	newData[0] = toupper(newData[0]);
	size_t size = newData.size();
	for (size_t i = n; i < size; i++) {
		newData[i] = tolower(newData[i]);
	}
	return;
}

//Validation
void isEmpty(string& newData) {
	while (newData == "\0") {
		cout << "Invalid input! Try again: ";
		getline(cin, newData);
	}
	return;
}
