#include <iostream>
#include <array>

using namespace std;

int main() {
	char alphabet[27]{}; // 26 letters in the alphabet + 1 null terminator
	int arraySize = size(alphabet);
	for (int i = 0; i < arraySize - 1; ++i) { // -1 to not change the null terminator
		alphabet[i] = 'A' + i;
	}
	cout << alphabet << endl;
	return 0;
}
