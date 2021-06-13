#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>      
#include <math.h> 
using namespace std;

class Normalize

{
public:
	// Calculates mean for use in normalize method
	float mean(vector<float> feature_column);
	// Calculates sd for use in normalize method
	float sd(vector<float> feature_column);
	// This method takes the data to normalize. How does it work? Exception seems to be thrown
	void normalize(vector < vector <float> > data);
};

