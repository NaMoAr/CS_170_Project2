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
	cout << "Welcome to Najmeh and Shubham Feature Selection Algorithm." << endl;
	

	cout << "Please enter the name of the file to test: ";
	string filename;
	cin >> filename;


	Classifier c;
	vector < vector<float> > data = c.train(filename);
	

	Normalize n;
	Validator v;

	
/*
	for (int j = 0; j < normalized_data.at(0).size(); j++) {
		for (int i = 0; i < normalized_data.size(); i++) {
			cout << normalized_data.at(i).at(j) << " ";
		}
	}
/*
	/*
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
	*/



	

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


	int feature = 0;
	for (int i = 0; i < data[0].size() - 1; i++) {
		feature++;
	}



	cout << endl;
	cout << "This dataset has " << feature << " features (not including the class atribute), with "<< data.size() <<" instances."<< endl;

	cout << "Beginning search" << endl;

	cout << endl;


	Search search;

	

	clock_t Start = clock();
	clock_t End;

	if (algorithm == 1) {
		
		cout << "Please wait while I normalize the data... Done!" << endl;
		cout << endl;
		vector < vector <float> > normalized_data = n.normalize(data);
		int number_of_features = normalized_data[0].size() - 1;
		search.Forward_selection(data, number_of_features);
		End = clock();
	}
	else if (algorithm == 2) {
		cout << endl;
		cout << "Please wait while I normalize the data... Done!" << endl;
		vector < vector <float> > normalized_data = n.normalize(data);
		int number_of_features = normalized_data[0].size() - 1;
		search.Backward_Elimination(data, number_of_features);
		End = clock();
	}
		
	float elapsedTime = ((float)(End - Start)) / CLOCKS_PER_SEC;
	cout << "Time spent on search: " << elapsedTime;



	if (algorithm == 1)
		search.Forward_selection(number_of_features);
	else if (algorithm == 2)
		search.Backward_Elimination(number_of_features);
	

	return 0;
}