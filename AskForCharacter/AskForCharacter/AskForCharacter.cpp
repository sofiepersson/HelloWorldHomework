#include <iostream>

using namespace std;

int main() {
	char character;
	char before;

	while (true) {
		cout << "Give me a character." << endl;
		cin >> character;
		if (character == 'A')
			before = 'Z';
		else if (character == 'a')
			before = 'z';
		else
			before = character - 1;
		cout << "Before that comes " << before << endl;
	}
	return 0;
}
