#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class Search
{
public: 
	vector<int> Forward_selection(vector < vector<float> > data,int number_of_features);
	void Backward_Elimination(vector < vector<float> > data, int number_of_features);


};

