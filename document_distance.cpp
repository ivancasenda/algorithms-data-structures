#include <iostream>
#include <fstream>
#include <string>

#include <math.h>
#include <vector>

using namespace std;

class vec {
public:
	string word;
	double total;
};



double calculate_cosine(vector<vec>& result1, vector<vec>& result2) {
	double dotproduct = 0;
	double magnitude1 = 0;
	double magnitude2 = 0;
	for (int i = 0; i < result1.size(); i++) {
		magnitude1 += (result1[i].total * result1[i].total);
		for (int j = 0; j < result2.size(); j++) {
			if (i == result1.size() - 1) {
				magnitude2 += (result2[j].total * result2[j].total);
			}
			if (result1[i].word == result2[j].word) {
				dotproduct += (result1[i].total * result2[j].total);
			}
		}
	}
	magnitude1 = sqrt(magnitude1);
	magnitude2 = sqrt(magnitude2);
	return dotproduct / (magnitude1 * magnitude2);
}

void document_distance() {

	string line;
	vector<vec> result1;
	ifstream file1 ("file1.txt");
	if (file1.is_open())
	{
		while (getline(file1, line, ' '))
		{
			bool found = false;
			for (int i = 0; i < result1.size(); i++) {
				if (line == result1[i].word) {
					result1[i].total++;
					found = true;
					break;
				}
			}
			if (found == false) {
				vec newWord;
				newWord.word = line;
				newWord.total = 1;
				result1.push_back(newWord);
			}
		}
		file1.close();
	}
	else {
		cout << "Unable to open file1" << endl;
	}
	vector<vec> result2;
	ifstream file2("file2.txt");
	if (file2.is_open())
	{
		while (getline(file2, line, ' '))
		{
			bool found = false;
			for (int i = 0; i < result2.size(); i++) {
				if (line == result2[i].word) {
					result2[i].total++;
					found = true;
					break;
				}
			}
			if (found == false) {
				vec newWord;
				newWord.word = line;
				newWord.total = 1;
				result2.push_back(newWord);
			}
		}
		file2.close();
	}
	else {
		cout << "Unable to open file2" << endl;
	}
	cout << calculate_cosine(result1, result2) << endl;
}

