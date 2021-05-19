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
	vector < vector<float> > train(string filename);
	int test(vector < vector <float> > data, vector<float> instance, vector <int> current_features);
	float euclidean_distance(vector <float> a,
		vector <float> b,
		vector <int> current_features);
};
