#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<double> doubleList;
	double x;
	while (cin >> x)
		doubleList.push_back(x);

	sort(doubleList.begin(), doubleList.end());
	cout << "doubleList: ";
	for(auto i = doubleList.begin(); i != doubleList.end(); ++i) {
		cout << *i << ' ';
	}

	cout << endl;

	// -2 -1 0 1 2 3 4 5 22 23

	typedef vector<int>::size_type vec_sz;
	vec_sz size = doubleList.size();
	vec_sz mid = size/2;
	vec_sz quarter1 = size/4;
	vec_sz quarter3 = quarter1 + mid;

	double Q1, Q2, Q3;
	Q2 = (size % 2 == 0 ? (doubleList[mid] + doubleList[mid-1]) / 2 : doubleList[mid]);
	Q1 = (size % 2 == 1 ? (doubleList[quarter1] + doubleList[quarter1-1]) / 2 : doubleList[quarter1]);
	Q3 = (size % 2 == 1 ? (doubleList[quarter3] + doubleList[quarter3-1]) / 2 : doubleList[quarter3]);

	cout << "First Quartile: " << Q1 << endl
		 << "Second Quartile: " << Q2 << endl
		 << "Third Quartile: " << Q3 << endl;

	return 0;
}
