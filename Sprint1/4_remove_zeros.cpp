#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

void ParseStr(const string& to_parse, list<int>& to_save);

int main() {
    string buffer;
    list<int> days;
    int days_num = 0;

    getline(cin, buffer);
    days_num = stol(buffer, nullptr, 10);

    getline(cin, buffer);
    ParseStr(buffer, days);

    auto it = days.begin();

    while (it != days.end()) {
        if (0 == *it) {
            it = days.erase(it);
        }
        else {
            ++it;
        }
    }

    for (auto it = days.begin(); it != days.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void ParseStr(const string& to_parse, list<int>& to_save) {
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