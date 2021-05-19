#include "Validator.h"
#include "Classifier.h"

float Validator::validate(vector<vector<float>> data, vector<int> current_features)
{
	float correct_classifications = 0;
	Classifier c;
	
	for (int i = 0; i < data.size(); i++) {	//iterate through all data
		vector <float> instance = data.at(i); //set the leave-one-out test data
		int predicted_class;
		predicted_class = c.test(data, instance, current_features);




		/*
		clock_t Start = clock();

		predicted_class = c.test(data, instance, current_features);

		clock_t End = clock();

		float elapsedTime = ((float)(End - Start)) / CLOCKS_PER_SEC;



		if (i % 50 == 0) {
			cout << "The pridicted class using instance [";
			for (int i = 0; i < instance.size() - 1; i++) {
				cout << instance[i] << ", ";
			}
			cout << " " << instance[instance.size() - 1];
			cout << "] and features {";
			for (int i = 0; i < current_features.size() - 1; i++) {
				cout << current_features[i] << ", ";
			}
			cout << current_features[current_features.size() - 1];
			cout << "} is " << predicted_class << endl;

			cout << "Comparing this instacne against other instacnes took " << elapsedTime << " seconds."<<endl;

		}
		*/
	


		if (predicted_class == instance.at(0))//compare the classes
			correct_classifications++;
	}
	return correct_classifications / (float)data.size();
}
