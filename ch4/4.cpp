#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double max;
	cout << "Enter the maximum value: ";
	cin >> max;
	double maxKeep = max;

	int maxLength = 1;
	while (max /= 10)
		maxLength++;

	cout << maxKeep << " " << maxLength << endl;

	// for (int i = 0; i < maxKeep; i++) {
	// 	cout << i << setw(maxLength + 2) << i*i << endl;
	// }

	return 0;
}
