#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	for (int i = 0; i < 100; i++) {
		cout << i << setw(6) << i*i << endl;
	}

	return 0;
}
