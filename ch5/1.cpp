#include <iostream>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

struct LineItem {
	string firstWord;
	string line;
	vector< vector<string> > permutedLines;
};

vector<string> getLines() {
	vector<string> lines;
	string line;

	while (getline(cin, line))
		lines.push_back(line);

	return lines;
}

vector< vector<string> > getPermutations(string line) {
	vector< vector<string> > permutations;
	vector<string> tempSentVector = split(line);
	
	for (vector<string>::size_type j = 0; j < tempSentVector.size(); j++) {
		string temp = tempSentVector[0];
		
		for (vector<string>::size_type i = 0; i < tempSentVector.size(); i++)
			tempSentVector[i] = tempSentVector[i + 1];
		tempSentVector[tempSentVector.size() - 1] = temp;

		permutations.push_back(tempSentVector);
	}

	return permutations;
}


int main() {
	vector<string> lines;
	lines = getLines();

	vector<LineItem> items;

	for (vector<string>::size_type i = 0; i < lines.size(); i++) {
		LineItem temp;
		temp.firstWord = lines[i][0];
		temp.line = lines[i];
		temp.permutedLines = getPermutations(temp.line);

		items.push_back(temp);
	}

	for (vector<LineItem>::size_type k = 0; k < items.size(); k++)
		cout << items[k].firstWord << " " << items[k].line << endl;

	return 0;
}
