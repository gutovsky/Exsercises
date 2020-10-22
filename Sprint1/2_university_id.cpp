#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void ParseStr(const string& to_parse, vector<int>& to_save);

int main() {
    string buffer;
    vector<int> ids;
    getline(cin, buffer);
    ParseStr(buffer, ids);
    getline(cin, buffer);
    int num_to_print = stol(buffer, nullptr, 10);
    map<int, int> students;
    for (auto it = ids.begin(); it != ids.end(); ++it) {
        students[*it]++;
    }

    for (int i = 0; i < num_to_print; ++i) {
        auto it = max_element(students.begin(), students.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b)->bool { return a.second < b.second; });
        cout << it->first << " ";
        it->second = 0;
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