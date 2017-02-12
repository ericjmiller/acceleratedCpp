#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> words;

	int shortest = 999;
	string shortestWord;
	int longest = 0;
	string longestWord;
	string word;
	while(cin >> word) {
		if(word.length() < shortest) {
			shortest= word.length();
			shortestWord = word;
		}

		if(word.length() > longest) {
			longest = word.length();
			longestWord = word;
		}
	}

	cout << "Shortest Word: " << shortestWord << "\t Length: " << shortest << endl;
	cout << "Longest Word: " << longestWord << "\t Length: " << longest << endl;

	return 0;
}
