#include "Search.h"

#include "Validator.h"

vector<int> Search::Forward_selection(vector < vector<float> > data, int number_of_features)


vector<int> Search::Forward_selection(int number_of_features)

{
	vector<int> set_of_features;
	vector<int> set_of_best_features;
	vector<int> overall_best_features;
	float accuracy = 0;
	bool repeated_feature = false;
	float previous_highest_accuracy = 0;

	Validator v;
	
	float default_rate = 0.0;

	float number_of_data = data.size();
	int number_of_data_in_class_2 = 0; 
	int number_of_data_in_class_1 = 0;

	for (int i = 0; i < data.size()-1; i++) {
		if (data[i][0] == 2) {
			number_of_data_in_class_2++;
		}
	}

	number_of_data_in_class_1 = number_of_data - number_of_data_in_class_2;

	int most_common_class;

	if (number_of_data_in_class_1 > number_of_data_in_class_2) {
		most_common_class = number_of_data_in_class_1;
	}
	else {
		most_common_class = number_of_data_in_class_2;
	}


	



	default_rate = most_common_class / number_of_data;

	cout << "Running nearest neighbor with no feature (default rate), using  leave-one-out evaluation, I get an accuracy of " << (float)default_rate*100.0 << "%"<< endl;

	cout << endl;


	for (int i = 1; i <= number_of_features; i++) {
		int selected_feature;
		float highest_acuuracy = 0;


	for (int i = 1; i <= number_of_features; i++) { 
		int selected_feature;
		float highest_acuuracy = 0;
		

		for (int j = 1; j <= number_of_features; j++) {
			repeated_feature = false;
			for (int k = 0; k < set_of_features.size(); k++) {
				if (set_of_features.at(k) == j) {
					repeated_feature = true;
				}
			}
			if (!repeated_feature) {
				cout << "Using feature(s) {";
				for (int f = 0; f < set_of_features.size(); f++) {
					cout << set_of_features.at(f) << ",";
				}
				cout << j << "} accuracy is ";


				vector<int> currently_set_of_features;
				currently_set_of_features = set_of_features;
				currently_set_of_features.push_back(j);
				//float accuracy = 1 + rand() % 99;
				float accuracy = v.validate(data, currently_set_of_features);
				currently_set_of_features.clear();
				cout << accuracy << "%" << endl;

				
				float accuracy = 1 + rand() % 99;
				cout << accuracy <<"%" << endl;

				if (accuracy > highest_acuuracy) {
					highest_acuuracy = accuracy;
					selected_feature = j;
				}
			}
		}


			set_of_features.push_back(selected_feature);
			if (highest_acuuracy > previous_highest_accuracy) {
				previous_highest_accuracy = highest_acuuracy;
				overall_best_features = set_of_features;
			}
			else {
				cout << "\n(Warning, accuracy, has decreased! Continuing search in case of local maxima)" << endl;

			}
			set_of_best_features = set_of_features;
			cout << "\nFeature set {";
			for (int m = 0; m < set_of_best_features.size() - 1; m++) {
				cout << set_of_best_features.at(m) << ",";
			}
			cout << set_of_best_features.at(set_of_best_features.size() - 1);
			cout << "} was best, accuracy is ";
			cout << highest_acuuracy << "%" << endl << endl;

	}
	
		set_of_features.push_back(selected_feature);
		if (highest_acuuracy > previous_highest_accuracy) {
			previous_highest_accuracy = highest_acuuracy;
			overall_best_features = set_of_features;
		}
		else {
			cout << "\n(Warning, accuracy, has decreased! Continuing search in case of local maxima)" << endl;
			
		}
		set_of_best_features = set_of_features;
		cout << "\nFeature set {";
		for (int m = 0; m < set_of_best_features.size() - 1; m++) {
			cout << set_of_best_features.at(m) << ",";
		}
		cout << set_of_best_features.at(set_of_best_features.size() - 1);
		cout << "} was best, accuracy is ";
		cout << highest_acuuracy << "%" << endl << endl;

	}


	cout << "Finished search!! The best feature subset is {";
	for (int r = 0; r < overall_best_features.size() - 1; r++) {
		cout << overall_best_features.at(r) << ",";
	}
	cout << overall_best_features.at(overall_best_features.size() - 1);
	cout << "}, which has an accuracy of " << previous_highest_accuracy << "%" << endl;
	return overall_best_features;



	
}


void Search::Backward_Elimination(vector < vector<float> > data, int number_of_features)

void Search::Backward_Elimination(int number_of_features)

{
	vector <int> set_of_features;
	vector <int> set_of_best_features;
	
	bool repeated_feature = false;
	float previous_highest_accuracy = 0;
	vector<int> overall_best_features;
	float highest_acuuracy = 0;

	Validator v;




	for (int w = 1; w <= number_of_features; w++) {
		set_of_features.push_back(w);
	}

	set_of_best_features = set_of_features;

	
	cout << "Using feature(s) {";
	for (int p = 0; p < set_of_features.size() - 1; p++)
		cout << set_of_features.at(p) << ",";
	cout << set_of_features.at(set_of_features.size() - 1) << "} accuracy is ";

	//accuracy

	//float accuracy = 1 + rand() % 99;
	float accuracy = v.validate(data, set_of_features);

	float accuracy = 1 + rand() % 99;

	cout << accuracy <<"%"<< endl << endl;
	if (accuracy > highest_acuuracy) {
		highest_acuuracy = accuracy;
	
	}

	
	for (int i = 1; i < number_of_features; i++) {
		
		repeated_feature = true;

		vector <int> temp_set_of_features;
		temp_set_of_features = set_of_features;
		highest_acuuracy = 0;

		for (int j = 0; j <= temp_set_of_features.size(); j++) {
			
			
			temp_set_of_features = set_of_features;

				
				
				for (int n = 0; n < temp_set_of_features.size(); ++n) {
					if (n == j) {
						temp_set_of_features.erase(temp_set_of_features.begin() + n);
					}
				}


				cout << "Using feature(s) {";
				for (int p = 0; p < temp_set_of_features.size() - 1; p++)
					cout << temp_set_of_features.at(p) << ",";
				cout << temp_set_of_features.at(temp_set_of_features.size() - 1) << "} accuracy is ";

				//accuracy

				//float accuracy = 1+ rand()%99;
				float accuracy = v.validate(data, temp_set_of_features);

				float accuracy = 1+ rand()%99;

				cout << accuracy <<"%"<< endl;
				if (accuracy > highest_acuuracy) {
					highest_acuuracy = accuracy;
					
					set_of_best_features = temp_set_of_features;
				}



				

		
		}

		
		set_of_features = set_of_best_features;
		temp_set_of_features = set_of_best_features;

		if (highest_acuuracy > previous_highest_accuracy) {
			previous_highest_accuracy = highest_acuuracy;
			overall_best_features = set_of_best_features;
		}
		else {
			cout << "\n(Warning, accuracy, has decreased! Continuing search in case of local maxima)" << endl;
		}
		
		cout << "\nFeature set {";
		for (int p = 0; p < temp_set_of_features.size() - 1; p++)
			cout << temp_set_of_features.at(p) << ",";
		cout << temp_set_of_features.at(temp_set_of_features.size() - 1);
		cout << "} was best, accuracy is ";
		cout << highest_acuuracy << "%" << endl << endl;
	}
	
	cout << "Finished search!! The best feature subset is {";
	for (int p = 0; p < overall_best_features.size() - 1; p++)
		cout << overall_best_features.at(p) << ",";
	cout << overall_best_features.at(overall_best_features.size() - 1);
	cout << "}, which has an accuracy of " << previous_highest_accuracy << "%" << endl;
}
