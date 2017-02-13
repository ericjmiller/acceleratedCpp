#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Words: " << endl;

	vector<string> wordList;
	vector<int> countList;

	string word;
	while (cin >> word) {
		bool inWordList = false;

		for(int i = 0; i != wordList.size(); i++) {
			if(word == wordList[i]) {
				inWordList = true;
				countList[i]++;
			}
		}

		if(!inWordList)
			wordList.push_back(word);
			countList.push_back(1);
	}

	for(int j = 0; j != wordList.size(); j++)
		cout << "Word: " << wordList[j] << "	" << "Count: " << countList[j] << endl;

	return 0;
}
