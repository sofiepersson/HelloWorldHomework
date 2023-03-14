#include <iostream>

using namespace std;

float Average(float*, int);

int main() {
	float array[100]{};
	cout << "How big do you want your array to be? The maximum size is 100: ";
	int arraySize{};
	cin >> arraySize;
	for (int i = 0; i < arraySize; ++i) {
		cout << "What number do you want to add?: ";
		float number;
		cin >> number;
		array[i] = number;
	}
	cout << "The average of those numbers is: " << Average(array, arraySize) << endl;

	return 0;
}

float Average(float* array, int size) {
	float sum{};
	for (int i = 0; i < size; ++i) {
		sum += array[i] / size;
	}
	return sum;
}
