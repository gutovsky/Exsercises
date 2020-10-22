#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ParseStr(const string& to_parse, vector<int>& to_save);

int main() {
	string buffer;
	vector<int> values;
	getline(cin, buffer);
	ParseStr(buffer, values);

	cout << (values[0] * values[1] * values[1] + values[2] * values[1] + values[3]) << endl;
}

void ParseStr(const string& to_parse, vector<int>& to_save) {
    string word;
    for (const char c : to_parse) {
        if (c == ' ') {
            if (!word.empty()) {
                to_save.push_back(stol(word, nullptr, 10));
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        to_save.push_back(stol(word, nullptr, 10));
    }
}