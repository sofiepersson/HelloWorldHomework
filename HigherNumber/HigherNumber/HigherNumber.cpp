#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int first, second;
	string input;
	cout << "Give me two numbers Separated by Comma. Like '-2,5'" << endl;
	getline(cin, input);
	stringstream ss(input);
	ss >> first;
	ss.ignore();
	ss >> second;
	if (first > second)
		cout << "The higher number is: " << first;
	else
		cout << "The higher number is: " << second;
	return 0;
}
