#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <exception>
#include <map>

using namespace std;

template <typename Type>
class Queue {
public:
    void put(const Type& element) {
        // просто вставим элемент в первый стек
        stack1_.push(element);
    }
    auto get() {
        // переложим все элементы из первого стека во второй,
        // так что первый элемент очереди окажется на вершине второго стека
        move_elements();
        // вытащим верхний элемент второго стека
        if (is_empty()) {
            throw (underflow_error("error"));
        }
        auto elem = stack2_.top();
        stack2_.pop();
        return elem;
    }
    uint64_t get_size() const {
        return stack1_.size() + stack2_.size();
    }

private:
    stack<Type> stack1_;
    stack<Type> stack2_;

    bool is_empty() const {
        return (stack1_.empty() && stack2_.empty());
    }

    void move_elements() {
        // Перекладывать во второй стек из первого
        // необходимо только тогда, когда во втором стеке
        // элементов не осталось. Иначе порядок очереди будет нарушен.
        if (stack2_.empty()) {
            while (!stack1_.empty()) {
                stack2_.push(stack1_.top());
                stack1_.pop();
            }
        }
    }
};

// Это компаратор для словаря функций
class strless {
public:
    bool operator() (const string& first, const string& second) const {
        return first.compare(second) < 0;
    }
};

void ParseStr(const string& to_parse, vector<string>& to_save);

// Функции-обертки для методов очереди
void Put(Queue<int>& queue, int num);
void Get(Queue<int>& queue, int num);
void GetSize(Queue<int>& queue, int num);

int main()
{
    map<string, void(*)(Queue<int>&, int), strless> command_functions = { {"put"s, Put}, {"get"s, Get}, {"get_size"s, GetSize} };
    string buffer;
    getline(cin, buffer);
    Queue<int> queue;

    uint64_t commands_num = stol(buffer, nullptr, 10);
    for (uint64_t i = 0; i < commands_num; ++i) {
        vector<string> command;
        getline(cin, buffer);
        ParseStr(buffer, command);
        if (1 == command.size()) {
            command_functions[command[0]](queue, 0);
        }
        else {
            command_functions[command[0]](queue, stol(command[1], nullptr, 10));
        }
    }
    
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

void Put(Queue<int>& queue, int num) {
    queue.put(num);
}

void Get(Queue<int>& queue, int num) {
    try {
        cout << queue.get() << endl;
    }
    catch (const underflow_error& e) {
        cout << e.what() << endl;
    }
}

void GetSize(Queue<int>& queue, int num) {
    cout << queue.get_size() << endl;
}

