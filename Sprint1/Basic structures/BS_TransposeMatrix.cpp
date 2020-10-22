#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ParseStr(const string& to_parse, vector<int>& to_save);

class Matrix {
public:
    Matrix(int n, int m, const vector<int>& elements) {
        rows_ = n;
        col_ = m;
        matrix_.reserve(n * m);
        matrix_ = elements;
    }
    int& operator()(size_t i, size_t j)
    {
        return matrix_[i * col_ + j];
    }

    int operator()(size_t i, size_t j) const
    {
        return matrix_[i * rows_ + j];
    }
    Matrix Transpose() {
        vector<int> result;
        for (int index = 0; index < rows_ * col_; ++index) {
            int i = index / rows_;
            int j = index % rows_;
            result.push_back(matrix_[col_ * j + i]);
        }
        return Matrix(col_, rows_, result);
    }
    void Print() {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < col_; ++j) {
                cout << (*this)(i, j) << " ";
            }
            cout << endl;
        }
    }

private:
    vector<int> matrix_;
    int rows_;
    int col_;
};

int main() {
    string buffer;
    getline(cin, buffer);
    int rows = stol(buffer, nullptr, 10);
    getline(cin, buffer);
    int col = stol(buffer, nullptr, 10);
    vector<int> elements;
    elements.reserve(rows * col);

    for (int i = 0; i < rows; ++i) {
        vector<int> part_elems;
        getline(cin, buffer);
        ParseStr(buffer, part_elems);
        elements.insert(elements.end(), part_elems.begin(), part_elems.end());
    }

    Matrix matrix(rows, col, elements);
    Matrix result = matrix.Transpose();
    result.Print();
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
