#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <bitset>

using namespace std;

void ParseStr(const string& to_parse, vector<int>& to_save);

int main() {
    string buffer;
    int number;

    getline(cin, buffer);
    number = stol(buffer, nullptr, 10);

    string binary = std::bitset<16>(number).to_string();
    auto it = find_if(binary.begin(), binary.end(), [] (char ch) { return (ch != '0');});
    binary.erase(binary.begin(), it);

    cout << binary << endl;
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