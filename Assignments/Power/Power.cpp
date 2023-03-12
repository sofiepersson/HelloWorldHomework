#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
	string input;
	int base, power, result;
	while (true) {
		cout << "Give me a base and a power separated by ^. Like '2 ^ 5': ";
		getline(cin, input);
		stringstream ss(input);
		ss >> base;
		ss.ignore();
		ss >> power;
		result = pow(base, power);
		for (int i = 1; i < power; ++i) {
			cout << base << "*";
		}
		cout << base << "=" << result << endl;
	}
	return 0;
}
