#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using namespace std;

bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else
			++iter;
	}
	return fail;
}

int main() {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store all the students' data.
	// Invariant:  students contains all the sutdent records read so far
	//             malen contains the length of the longest name in students
	while (read(cin, record)) {
		// find length of longest name
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// alphaetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		// write the name, padded on the right to maxlen + 1 characters
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		// compute and write the grade
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
