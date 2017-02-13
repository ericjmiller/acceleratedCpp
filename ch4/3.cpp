#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int max;
	cout << "Enter the maximum value: ";
	cin >> max;
	int maxKeep = max;

	int maxLength = 1;
	while (max /= 10)
		maxLength++;

	for (int i = 0; i < maxKeep; i++) {
		cout << i << setw(maxLength + 2) << i*i << endl;
	}

	return 0;
}
