#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

class Validator
{
public:
	// This is basically the constructor that takes in current data current features to get accuracy of NN classfier. 
	float validate(vector < vector <float> > data,
		vector <int> current_features);

	
};

