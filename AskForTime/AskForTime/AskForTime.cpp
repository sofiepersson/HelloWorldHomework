#include <iostream>

using namespace std;

int main() {
	int totalSeconds, hours, minutes, seconds;

	cout << "How many seconds have passed?" << endl;
	cin >> totalSeconds;

	hours = totalSeconds / 3600;
	totalSeconds %= 3600;

	minutes = totalSeconds / 60;
	totalSeconds %= 60;

	seconds = totalSeconds;
	

	cout << hours << ":" << minutes << ":" << seconds << endl;

	return 0;
}
