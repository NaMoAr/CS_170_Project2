#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Classifier
{
public:
	// This method basically just opens the file and reads every line. Pushes data into vector
	vector < vector<float> > train(string filename);
	// When testing new instance, need data, the instance, and features that are being used
	int test(vector < vector <float> > data, vector<float> instance, vector <int> current_features);
	// Used to find nearest neighbor
	float euclidean_distance(vector <float> a,
		vector <float> b,
		vector <int> current_features);
};
