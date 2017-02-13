#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int readWords(istream& in, vector<string>& wordList){
	if (in) {
		wordList.clear();

		string word;
		while (in >> word)
			wordList.push_back(word);

		in.clear();
	}

	return in;
}

int main() {
	vector<string> wordList;
	vector<string> uniqueWordList;
	vector<int> countList;
	int wordCount = 0;

	readWords(cin, wordList);

	sort(wordList.begin(), wordList.end());

	string previousWord = "";

	for (vector<string>::size_type i = 0; i != wordList.size(); i++, wordCount++) {
		string currentWord = wordList[i];
		int currentCount = 0;

		if (currentWord != previousWord) {
			for(int i = 0; i != wordList.size(); i++) {
				if(currentWord == wordList[i]) {
					currentCount++;
				}
			}
			uniqueWordList.push_back(currentWord);
			countList.push_back(currentCount);
		}

		previousWord = currentWord;
	}

	cout << "Count: " << wordCount << endl;
	for (vector<string>::size_type j = 0; j != uniqueWordList.size(); j++)
		cout << setw(10) << uniqueWordList[j] << " " << countList[j] << endl;

	return 0;
}
