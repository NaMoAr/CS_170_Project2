I.  Introduction

<br />This project, Feature Selection with Nearest Neighbor, is the second project for this class. In this project, we gain further insight into machine learning by using the provided datasets to find the set of best features. Along with this, we use the nearest neighbor classifier to determine the accuracy for a specific set of features. . We also measure the accuracy of our classifier by using the one-leave-out cross validation function.
Finding the best features is an optimization problem. As a result, we use two Greedy search algorithms to implement search selection. The two algorithms we use specificialy are forward selection and backward elimination. Regardless of which algorithm is used, we obtain the node with the maximum score (set of best features). At the end of this project, we generate a trace of the algorithm.

II.	Code Design

<br />We designed the project in an object-oriented manner. There are four classes in total, each taking care of some part of the program. The Search class has the forward selection and backward elimination functions. Inside of these two classes we defined an object of type Validator to access the validate function. The validate function itself calls the function test in the Classifier class so we have an object of type Classifier inside the validate function. The test function calls the euclidean_distance function to calculate the distance between two nodes. The train function inside the Classifier class is just to read the data from input and put it in a 2D vector, and is called directly by the driver. 
<br />The Normalize class has three functions: mean, sd, and normalize that obviously apply the normalization task, and is called by the driver after we read the data from the input file and generate a 2D vector.
<br />We did not apply optimization for our program, but one possible way to optimize the program is taking advantage of Triangle Inequality for finding Euclidean distances. Meaning that we can find the Triangle Inequality bound and reduce the computations. Another way to optimize would be to find the best K-value for the KNN classifier  which would reduce the sensitivity of nodes to give a higher accuracy. 

![UML Class (1)](https://user-images.githubusercontent.com/59351131/123024263-a199e900-d38d-11eb-9f76-92c8b808655c.png)


  
III. Dataset Detail

<br />Small Dataset: Number of features: 10, number of instances: 100
<br />Large Dataset: Number of features: 40, number of instances: 1000
<br />According to the following scatter plots, features 1 and 3 from the small personal dataset and features 32 and 15 from the large dataset have a natural classification as the blue dots (class 1) and orange dots (class 2) are separable. This does not give us a 100% accuracy though, since there are some orange dots in the area of blue dots. However, there is a great chance that these features get selected by the search algorithms. 

![1](https://user-images.githubusercontent.com/59351131/123021799-9a70dc00-d389-11eb-9541-7bb4ae3bb2f5.PNG)
![2](https://user-images.githubusercontent.com/59351131/123021927-cf7d2e80-d389-11eb-94c4-1e6358456e07.PNG)


In the two scatter plots below, there is no such boundary between the blue and orange dots. This means that using these two features may result in a very low accuracy and the search algorithm would not choose them most likely. 

![3](https://user-images.githubusercontent.com/59351131/123021978-e459c200-d389-11eb-994f-dec70b12a15b.PNG)
![4](https://user-images.githubusercontent.com/59351131/123022000-ede32a00-d389-11eb-9f32-93594efb05f2.PNG)


IIII.  Algorithms

1. 	Forward Selection
<br />initial state: Empty Set: No features
<br />Operators: Add a feature.
<br />Evaluation Function: K-fold cross validation
<br />Forward selection is one of the Greedy algorithms implemented in this project. The algorithm starts with no features initially in the node and the accuracy is just the default rate. Then it would calculate the accuracy for each of the features and select the one with highest accuracy and then combine it with the rest of the feature. This process continues until there are no more features left to combine. (Since we continue the search in the case of local maxima). 
2. 	Backward Elimination
<br />initial state: Set of all features
<br />Operators: Remove a feature
<br />Evaluation Function: K-fold cross validation
<br />Backward Elimination is one of the Greedy algorithms implemented in this project. The algorithm starts with all features, then removes one of the features and calculates the accuracy. Then it grabs the set of features with highest accuracy and repeats the process I just mentioned. It continues until there is no more feature to remove (Since we continue the search in the case of local maxima). 
3.	Nearest Neighbor Classifier 
	<br />The KNN algorithm is supervised machine learning. We used this classifier to predict the class label of the test instance. To find the class label we measured the distance of the test instance against all the training instances and then we assigned the label class of the closest train instance to the test instance. 
4.  One-Leave-Out cross validation
	<br />To find the accuracy, we used One-Leave-Out cross validation meaning we selected one of the instances each time as the test instance. We then ran the KNN algorithm to find the class label. We do this process for all the instances in the dataset.Then we divide the number of correct predictions for class labels by the number of instances in total and that gives us the accuracy. 

V. Analysis

<br />Experiment 1: Comparing Forward Selection vs Backward Elimination
	<br />In the small dataset, forward selection is much more accurate compared to backward elimination when the dataset is normalized. When it is not normalized however, the accuracy does not change. In the large dataset, forward selection has a much better accuracy by 9% when normalized. This result is explained through the benefits of forward selection.
	<br />Each of the algorithms have unique benefits. One benefit of forward selection is that it starts with only one feature and is not dependent on previous features.  As the algorithm runs, there is independence between the various different features. With backward selection, the benefit is that it is a bit simpler to implement as all of the features are considered initially. The least important features are removed early on. 
	<br />Both of the algorithms also have certain drawbacks. With forward selection, the main drawback is that the algorithm is unable to remove features that become unhelpful later on. Likewise, the main drawback with backward elimination is that the algorithm is unable to determine the usefulness of features after they have been discarded. 
	<br />The forward selection executed in 5.431 sec and 5.441 sec for the small datasets, and backward elimination executed in 5.693 sec and 5.923 sec. As we saw here, forward selection was slightly faster than backward elimination. 
	<br />For the small datasets, we have an accuracy of 82% and 74% with no feature selection. However we get much higher accuracy when we use feature selection. For the personal small dataset, the best feature subset is {1,3}, which has an accuracy of 0.92%. For a general small dataset, the best feature subset is {5,3}, which has an accuracy of 0.92%. This means we get a better classifier using the feature selection in this case. In the cases where we have better accuracy for no feature selection, we simply assign unseen data to the class with more instances.

<br />Experiment 2: Effect of normalization
	<br />Normalization, also referred to as feature scaling, is a very important process needed to avoid false classification due to an unstandardized scale. If all the data is normalized before any algorithms are run, then there will be equal weight between all of the features.
	<br />According to the following table, the accuracy for the same set of features is higher or the same for the normalized data than the unnormalized data.
  
![5](https://user-images.githubusercontent.com/59351131/123022615-e2443300-d38a-11eb-85d5-dda21153203c.PNG)

<br />In terms of the result of the search algorithms, the accuracy using normalized data and unnormalized data gave us the same result for forward selection. However, backward selection on unnormalized data gave us a higher accuracy and also a different set for the best set of features. For example, for the personal small dataset, the backward elimination gave us  {1} with accuracy of 0.86 with normalized data, but {1,3} with an accuracy of 0.92 with unnormalized data. The same thing happened using the general small dataset. With normalized data we got {2,4,5,7,10} with an accuracy of 0.82, with unnormalized data we got  {2,4,5,7,10}, which has an accuracy of 0.83%. 
<br />The reason for decreasing the accuracy when we normalize data for backward-elimination is because we change the scale of the features and that has a direct effect on accuracy. The way we calculate accuracy is finding the distance between two points using Euclidean distance. When we change the scale of the points, we would have different distances that lead to a different accuracy. 

![6](https://user-images.githubusercontent.com/59351131/123022723-11f33b00-d38b-11eb-8562-126ae79b763d.PNG)

<br />VI.  Conclusion

<br />	Through the process of working on this project, we gained a much better insight creating algorithms to pick features and working with datasets to perform classifications. In the conclusion of this project, it is evident that making smart decisions on choosing the best algorithm along with managing the size of the dataset has a big effect on performance of the classifier. For this project, we looked at various different performance characteristics to analyze our classification including accuracy and execution time.
<br />When implementing the feature search algorithms, forward selection gives the highest accuracy for almost every situation. This stays true regardless of the size of the dataset or whether the dataset is normalized or not. Normalizing the dataset also generally helps, although we did have a case where accuracy reported by the Backward-Elimination decreased when we normalized.
<br />For the backwards elimination algorithm in the general small dataset, we never had 100% accuracy. Through the graphs, we are able to visualize and see that certain instances are miscategorized.
<br />Each of the Forward-Selection and Backward-Elimination has its own advantages and disadvantages. The best approach is to combine both algorithms and balance their pros and cons. Bi-directional Search is the method that uses both algorithms and provides a better search result than the two algorithms separately. 

<br />VI. Trace of my small dataset

<br />Personal small dataset:
<br />Welcome to Najmeh and Shubham Feature Selection Algorithm.
<br />Please enter the name of the file to test: small57.txt
<br />Type the number of the algorithm you want to run.
<br />1. Forward Selection
<br />2. Backward Elimination
<br />3. Berties's Special Algorithm
<br />1

<br />This dataset has 10 features (not including the class atribute), with 100 instances.

<br />Please wait while I normalize the data... Done!

<br />Running nearest neighbor with no feature (default rate), using  leave-one-out evaluation, I get an accuracy of 82%

<br />Using feature(s) {1} accuracy is 0.86%
<br />Using feature(s) {2} accuracy is 0.75%
<br />Using feature(s) {3} accuracy is 0.67%
<br />Using feature(s) {4} accuracy is 0.72%
<br />Using feature(s) {5} accuracy is 0.72%
<br />Using feature(s) {6} accuracy is 0.66%
<br /><br />Using feature(s) {7} accuracy is 0.65%
<br />Using feature(s) {8} accuracy is 0.63%
<br />Using feature(s) {9} accuracy is 0.74%
<br />Using feature(s) {10} accuracy is 0.79%

<br />Feature set {1} was best, accuracy is 0.86%

<br />Using feature(s) {1,2} accuracy is 0.8%
<br />Using feature(s) {1,3} accuracy is 0.92%
<br />Using feature(s) {1,4} accuracy is 0.8%
<br />Using feature(s) {1,5} accuracy is 0.76%
<br />Using feature(s) {1,6} accuracy is 0.8%
<br />Using feature(s) {1,7} accuracy is 0.76%
<br />Using feature(s) {1,8} accuracy is 0.8%
<br />Using feature(s) {1,9} accuracy is 0.81%
<br />Using feature(s) {1,10} accuracy is 0.84%

<br />Feature set {1,3} was best, accuracy is 0.92%

<br />Using feature(s) {1,3,2} accuracy is 0.82%
<br />Using feature(s) {1,3,4} accuracy is 0.89%
<br />Using feature(s) {1,3,5} accuracy is 0.86%
<br />Using feature(s) {1,3,6} accuracy is 0.81%
<br />Using feature(s) {1,3,7} accuracy is 0.83%
<br />Using feature(s) {1,3,8} accuracy is 0.89%
<br />Using feature(s) {1,3,9} accuracy is 0.82%
<br />Using feature(s) {1,3,10} accuracy is 0.84%

<br />(Warning, accuracy, has decreased! Continuing search in case of local maxima)

<br />Feature set {1,3,4} was best, accuracy is 0.89%

<br />Using feature(s) {1,3,4,2} accuracy is 0.8%
<br />Using feature(s) {1,3,4,5} accuracy is 0.85%
<br />Using feature(s) {1,3,4,6} accuracy is 0.82%
<br />Using feature(s) {1,3,4,7} accuracy is 0.86%
<br />Using feature(s) {1,3,4,8} accuracy is 0.8%
<br />Using feature(s) {1,3,4,9} accuracy is 0.89%
<br />Using feature(s) {1,3,4,10} accuracy is 0.84%

<br />(Warning, accuracy, has decreased! Continuing search in case of local maxima)

<br />Feature set {1,3,4,9} was best, accuracy is 0.89%

<br />Using feature(s) {1,3,4,9,2} accuracy is 0.78%
<br />Using feature(s) {1,3,4,9,5} accuracy is 0.86%
<br />Using feature(s) {1,3,4,9,6} accuracy is 0.81%
<br />Using feature(s) {1,3,4,9,7} accuracy is 0.79%
<br />Using feature(s) {1,3,4,9,8} accuracy is 0.84%
<br />Using feature(s) {1,3,4,9,10} accuracy is 0.83%

<br />(Warning, accuracy, has decreased! Continuing search in case of local maxima)

<br />Feature set {1,3,4,9,5} was best, accuracy is 0.86%

<br />Using feature(s) {1,3,4,9,5,2} accuracy is 0.75%
<br />Using feature(s) {1,3,4,9,5,6} accuracy is 0.77%
<br />Using feature(s) {1,3,4,9,5,7} accuracy is 0.77%
<br />Using feature(s) {1,3,4,9,5,8} accuracy is 0.78%
<br />Using feature(s) {1,3,4,9,5,10} accuracy is 0.8%

<br />(Warning, accuracy, has decreased! Continuing search in case of local maxima)

<br />Feature set {1,3,4,9,5,10} was best, accuracy is 0.8%

<br />Using feature(s) {1,3,4,9,5,10,2} accuracy is 0.77%
<br />Using feature(s) {1,3,4,9,5,10,6} accuracy is 0.79%
<br />Using feature(s) {1,3,4,9,5,10,7} accuracy is 0.75%
<br />Using feature(s) {1,3,4,9,5,10,8} accuracy is 0.73%

<br />(Warning, accuracy, has decreased! Continuing search in case of local maxima)

<br />Feature set {1,3,4,9,5,10,6} was best, accuracy is 0.79%

<br />Using feature(s) {1,3,4,9,5,10,6,2} accuracy is 0.79%
<br />Using feature(s) {1,3,4,9,5,10,6,7} accuracy is 0.73%
<br />Using feature(s) {1,3,4,9,5,10,6,8} accuracy is 0.74%

<br />(Warning, accuracy, has decreased! Continuing search in case of local maxima)

<br />Feature set {1,3,4,9,5,10,6,2} was best, accuracy is 0.79%

<br />Using feature(s) {1,3,4,9,5,10,6,2,7} accuracy is 0.79%
<br />Using feature(s) {1,3,4,9,5,10,6,2,8} accuracy is 0.76%

<br />(Warning, accuracy, has decreased! Continuing search in case of local maxima)

<br />Feature set {1,3,4,9,5,10,6,2,7} was best, accuracy is 0.79%

<br />Using feature(s) {1,3,4,9,5,10,6,2,7,8} accuracy is 0.75%

<br />(Warning, accuracy, has decreased! Continuing search in case of local maxima)

<br />Feature set {1,3,4,9,5,10,6,2,7,8} was best, accuracy is 0.75%

<br />Finished search!! The best feature subset is {1,3}, which has an accuracy of 0.92%


<br />**To run the code:**
<br />**Clone the repository in your local machine and use Visual Studio IDE to run it, or use a G++ Compiler to compile and the code inside the CS_CS170_Project2 folder. Run g++ /*.cpp and then ./a.exe**

