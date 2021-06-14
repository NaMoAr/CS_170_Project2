#include "Normalize.h"

float Normalize::mean(vector<float> feature_column)
{
	float sum = 0;
	for (int i = 0; i < feature_column.size(); i++) {
		sum += feature_column.at(i);
	}
    return sum / feature_column.size();
}

float Normalize::sd(vector<float> feature_column)
{
	float a = 0;
	for (int i = 0; i < feature_column.size(); i++) {
		a += (feature_column.at(i) * feature_column.at(i));
	}

	float b = 0;
	for (int i = 0; i < feature_column.size(); i++) {
		b += feature_column.at(i);
	}

	return sqrt((a - ((b * b)/ feature_column.size()))  / (feature_column.size()-1));
}

vector < vector <float> > Normalize::normalize(vector < vector <float> > data) {

	vector <float> feature_column;
	for (int j = 1; j < data.at(0).size(); j++) {
		feature_column.clear();
		for (int i = 0; i < data.size(); i++) {
			feature_column.push_back(data.at(i).at(j));
		}
		float feature_column_mean = mean(feature_column);
		float feature_column_sd = sd(feature_column);
		for (int i = 0; i < data.size(); i++) {
			data.at(i).at(j) = (data.at(i).at(j) - feature_column_mean) / feature_column_sd;
		}
	}

	return data;
}