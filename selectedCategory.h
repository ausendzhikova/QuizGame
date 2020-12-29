#pragma once
#include <string>
using namespace std;


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
