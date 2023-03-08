#include <cstdio>

void Swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int main() {
	int four = 4;
	int five = 5;
	int* ptrFour = &four;
	int* ptrFive = &five;
	printf("This is four: %d, This is five: %d\n", four, five);
	Swap(ptrFour, ptrFive);
	printf("This used to be four: %d, This used to be five: %d\n", four, five);
	return 0;
}
