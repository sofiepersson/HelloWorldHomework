#include <cstdio>

int main() {
	int a = 50;
	int b = 25;
	printf("a: %d, b: %d\n", a, b);
	int c = a;
	a = b;
	b = c;
	printf("Now a is %d and b is %d\n", a, b);
	return 0;
}
