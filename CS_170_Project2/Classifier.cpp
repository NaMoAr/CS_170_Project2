#include "Classifier.h"

vector<vector<float>> Classifier::train(string filename)
{
	string line;
	vector < vector<float> > data;
	ifstream file(filename.c_str());
	if (file.is_open()) {
		while (getline(file, line)) {
			vector <float> row;
			stringstream lineStream(line);

			float value;
			while (lineStream >> value) {
				row.push_back(value);
			}
			data.push_back(row);
		}
		file.close();
	}
	else {
		cout << "Unable to open file" << endl;
	}
	return data;
}

int Classifier::test(vector < vector <float> > data, vector<float> instance, vector <int> current_features)
{
	
		
		float min_dist = 100000;
		vector <float> closest_neighbor;

		for (int k = 0; k < data.size(); k++) { //iterate through all data to get 1 nearest neighbor
			if (instance != data.at(k)) { //get distance between current data & test
				float distance = euclidean_distance(instance, data.at(k), current_features);

			

				if (distance < min_dist) { //get min distance
					min_dist = distance;
					closest_neighbor = data.at(k);
					
				}
			}
		}



		//implementated for part 2 of the project to show some steps
		/*
			cout << "The closest distacne for inastance [";
			for (int i = 0; i < instance.size() - 1; i++) {
				cout << instance[i] << ", ";
			}
			cout << " " << instance[instance.size() - 1];
			cout << "] and features {";
			for (int i = 0; i < current_features.size() - 1; i++) {
				cout << current_features[i] << ", ";
			}
			cout << current_features[current_features.size() - 1];
			cout << "} is " << min_dist << endl;
		*/

	return closest_neighbor.at(0);
}

float Classifier::euclidean_distance(vector<float> a, vector<float> b, vector<int> current_features)
{
	float x = 0;
	for (int i = 0; i < current_features.size(); i++) {
		x += (pow(a.at(current_features.at(i)) - b.at(current_features.at(i)), 2));
	}
	return sqrt(x);	
}
