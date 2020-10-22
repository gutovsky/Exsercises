#include "Parsing.h"

using namespace std;

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