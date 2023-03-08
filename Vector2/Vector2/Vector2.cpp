#include <iostream>

using namespace std;

struct Vector2D {
	int x, y;

	Vector2D Add(Vector2D a, Vector2D b) {
		Vector2D result;
		result.x = a.x + b.x;
		result.y = a.y + b.y;
		return result;
	}
};

int main() {
	Vector2D a;
	a.x = 3;
	a.y = 2;
	Vector2D b;
	b.x = -1;
	b.y = -2;
	Vector2D result = a.Add(a, b);
	cout << "Adding Vector(3,2) and (-1,-2)..." << endl;
	cout << "Result: Vector(" << result.x << "," << result.y << ")" << endl;
	
	return 0;
}
