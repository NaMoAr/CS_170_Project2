#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include "accuracy.h"
using namespace std;

class Search
{
public: 
	vector<int> Forward_selection(int number_of_features);
	void Backward_Elimination(int number_of_features);


};

