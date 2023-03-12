#include <iostream>
#include <iomanip>

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
	
	cout << setfill('0') << setw(2) << hours << ":"
		<< setfill('0') << setw(2) << minutes << ":"
		<< setfill('0') << setw(2) << seconds << endl;

	return 0;
}
