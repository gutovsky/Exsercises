#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cwchar>

using namespace std;

void ParseStr(const string& to_parse, vector<int>& to_save);
int ToIndex(char ch);

int main() {
    std::wifstream fichier("input.txt");
    map<wchar_t, int> all_chars;
    std::wstring str_w1;
    std::wstring str_w2;

    getline(fichier, str_w1);
    getline(fichier, str_w2);

    //str_w1 = to_wstring

    if (str_w1.length() != str_w2.length()) {
        cout << "False" << endl;
        return 0;
    }

    for (int i = 0; i < str_w1.length(); ++i) {
        all_chars[str_w1[i]]++;
        all_chars[str_w2[i]]--;
    }
    for (auto it = all_chars.begin(); it != all_chars.end(); ++it) {
        if (it->second != 0) {
            cout << "False" << endl;
            return 0;
        }
    }
    cout << "True" << endl;
    return 0;
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