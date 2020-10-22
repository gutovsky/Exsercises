#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void ParseStr(const string& to_parse, vector<int>& to_save);

int main() {
    string buffer;
    vector<int> numbers;
    int length = 0;

    getline(cin, buffer);
    length = stol(buffer, nullptr, 10);

    getline(cin, buffer);
    ParseStr(buffer, numbers);

    map<int, int> check_map;
    for (int i = 0; i < length; ++i) {
    	check_map[numbers[i]]++;
    	if (1 < check_map[numbers[i]]) {
    		cout << numbers[i] << endl;
    		return 0;
    	}
    }
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