#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Calculator {
public:
    enum class Operation {
        ADD,
        SUBSTRUCT,
        MULTIPLY,
        DEVIDE
    };

    void SetUserInput(const vector<string>& tokens);
    int GetResult();
private:
    stack<int> operands_;

    void PressNumber(int number);
    void PressOperation(Operation operation);
    Operation ConvertToOp(const string& s);
    bool GetNumber(const std::string& s, int* result);

    static int Addition(int num1, int num2) {
        return num1 + num2;
    }
    static int Substruction(int num1, int num2) {
        return num1 - num2;
    }
    static int Multiplication(int num1, int num2) {
        return num1 * num2;
    }
    static int Devision(int num1, int num2) {
        return num1 / num2;
    }
    vector<int(*)(int, int)> operations_ = { Addition, Substruction, Multiplication, Devision };
};

void Calculator::SetUserInput(const vector<string>& tokens) {
    for (int i = 0; i < tokens.size(); ++i) {
        int number = 0;
        if (GetNumber(tokens[i], &number)) {
            PressNumber(number);
        }
        else {
            PressOperation(ConvertToOp(tokens[i]));
        }
    }
}

Calculator::Operation Calculator::ConvertToOp(const string& s) {
    if (s == "+") {
        return Calculator::Operation::ADD;
    }
    if (s == "-") {
        return Calculator::Operation::SUBSTRUCT;
    }
    if (s == "*") {
        return Calculator::Operation::MULTIPLY;
    }
    if (s == "/") {
        return Calculator::Operation::DEVIDE;
    }
}

bool Calculator::GetNumber(const std::string& s, int* result)
{
    if (s.empty()) {
        return false;
    }

    if (s[0] == '-' && s.size() == 1) {
        return false;
    }
    
    if (!isdigit(s[0]) && s[0] != '-') {
        return false;
    }

    *result = stol(s, nullptr, 10);
    return true;
}


void Calculator::PressNumber(int number) {
    operands_.push(number);
}

void Calculator::PressOperation(Operation operation) {
    int num2 = operands_.top();
    operands_.pop();
    int num1 = operands_.top();
    operands_.pop();
    operands_.push(operations_[static_cast<int>(operation)](num1, num2));
}

int Calculator::GetResult() {
    return operands_.top();
}

void ParseStr(const string& to_parse, vector<string>& to_save) {
    string word;
    for (const char c : to_parse) {
        if (c == ' ') {
            if (!word.empty()) {
                to_save.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        to_save.push_back(word);
    }
}

int main() {
    Calculator calc;
    string buffer;
    vector<string> expr;
    getline(cin, buffer);
    ParseStr(buffer, expr);
    calc.SetUserInput(expr);
    cout << calc.GetResult() << endl;
}
