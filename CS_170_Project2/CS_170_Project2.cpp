#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Search.h"
using namespace std;

int main(int argc, char* argv[]) {
	cout << "Welcome to Najmeh's Feature Selection Algorithm." << endl;
	

	cout << "Please enter total number of features: ";
	int number_of_features;
	cin >> number_of_features;


	int algorithm = 0;
	cout << "Type the number of the algorithm you want to run. " << endl;
	cout << "1. Forward Selection" << endl;
	cout << "2. Backward Elimination" << endl;
	cout << "3. Berties's Special Algorithm" << endl;
	while (algorithm < 1 || algorithm > 3) {
		cin >> algorithm;
	}

	cout << "Beginning search" << endl;
	cout << endl;


	Search search;


	if (algorithm == 1)
		search.Forward_selection(number_of_features);
	else if (algorithm == 2)
		search.Backward_Elimination(number_of_features);
	
	return 0;
}