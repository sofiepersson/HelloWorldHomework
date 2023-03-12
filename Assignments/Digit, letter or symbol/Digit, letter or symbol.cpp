#include <iostream>

using namespace std;

int main() {
	char input;
	while (true) {
		cout << "Give me a character: ";
		cin >> input;

		if (input >= '0' && input <= '9')
			cout << "That's a digit." << endl;
		else if (input >= 'a' && input <= 'z')
			cout << "That's a lower-case letter." << endl;
		else if (input >= 'A' && input <= 'Z')
			cout << "That's an upper-case letter." << endl;
		else
			cout << "That's a symbol." << endl;
	}
	return 0;
}
