#include <cstdio>

int CountWords(char*);

int main() {
	printf("Give me a text and I will tell you how many words are in it.\n");
	char input[100]{};
	scanf_s("%99[^\n]", input, 100);
	int count = CountWords(input);
	printf("Your sentence contains %d words.\n", count);

	return 0;
}

int CountWords(char* text) {
	bool isAtWord{ false };
	int count{};
	while (*text) {
		if (*text == ' ') {
			isAtWord = false;
		}
		else if (!isAtWord) {
			isAtWord = true;
			++count;
		}
		++text;
	}
	return count;
}
