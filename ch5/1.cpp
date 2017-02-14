#include <iostream>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

Struct LineItem {
	string firstWord;
	string line;
	vector<vector<string>> permutedLines;
};

vector<string> getLines() {
	vector<string> lines;
	string line;

	while (getline(cin, line))
		lines.push_back(line);

	return lines;
}


int main() {
	string sent;
	vector<string> sentVector;

	while (getline(cin, sent)) {
		vector<string> tempSentVector = split(sent);
		
		for (vector<string>::size_type j = 0; j < tempSentVector.size(); j++) {
			string temp = tempSentVector[0];
			
			for (vector<string>::size_type i = 0; i < tempSentVector.size(); i++)
				tempSentVector[i] = tempSentVector[i + 1];
			tempSentVector[tempSentVector.size() - 1] = temp;

			cout << endl;
		}
	}
	return 0;
}
