#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Search.h"
#include "Validator.h"
#include "Normalize.h"
#include "Classifier.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "Welcome to Najmeh's Feature Selection Algorithm." << endl;
	
	// Take in file here
	cout << "Please enter the name of the file to test: ";
	string filename;
	cin >> filename;

	// Create a classfier object
	Classifier c;
	// Taking data from file and pushing it into a vector
	vector < vector<float> > data = c.train(filename);
	

	Normalize n;
	Validator v;
	n.normalize(data);


	if (filename == "small.txt") {
	int number_of_features = data[0].size()-1;

	clock_t Start1 = clock();

	float acuuracy_1 = v.validate(data, { 3, 5, 7 });

	clock_t End1 = clock();

	float elapsedTime1 = ((float)(End1 - Start1))/ CLOCKS_PER_SEC;

	
		cout << "The accuracy using features {3,5,7} is: " << acuuracy_1<<endl;
		cout << "The validation for this feature set took " << elapsedTime1 <<" seconds." << endl;
	}


	if (filename == "large.txt") {
	clock_t Start2 = clock();

	float acuuracy_2 = v.validate(data, { 1, 15, 27 });

	clock_t End2 = clock();

	float elapsedTime2 = ((float)(End2 - Start2) / CLOCKS_PER_SEC);


	
		cout <<"The accuracy using features {3,15,27} is: " <<acuuracy_2 << endl;
		cout << "The validation for this feature set took " << elapsedTime2 << " seconds.";
	}
	



	/*
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
		search.Forward_selection(data,number_of_features);
	else if (algorithm == 2)
		search.Backward_Elimination(data,number_of_features);
		*/
	return 0;
}