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
	float mean(vector<float> feature_column);
	float sd(vector<float> feature_column);
	vector < vector <float> > normalize(vector < vector <float> > data);
};

