#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

void ParseStr(const string& to_parse, vector<int>& to_save);

int main() {
    string buffer;
    vector<int> first;
    int second_num;
    int length_first = 0;

    getline(cin, buffer);
    length_first = stol(buffer, nullptr, 10);

    getline(cin, buffer);
    ParseStr(buffer, first);

    getline(cin, buffer);
    second_num = stol(buffer, nullptr, 10);

    int first_num = 0;

    for (int i = 0; i < first.size(); ++i) {
        first_num += pow(10, i) * first[first.size() - i - 1];
    }

    int result_num = first_num + second_num;
    vector<int> result;
    while (0 != result_num) {
        result.push_back(result_num % 10);
        result_num /= 10;
    }

    reverse(result.begin(), result.end());

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
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