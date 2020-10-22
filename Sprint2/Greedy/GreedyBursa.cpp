#include iostream
#include string
#include vector

using namespace std;

void ParseStr(const string& to_parse, vectorint& to_save);
int CalcIncome(const vectorint& prices);

int main()
{
    string buffer;
    getline(cin, buffer);
    int days_num = stol(buffer, nullptr, 10);

    vectorint prices;
    getline(cin, buffer);
    ParseStr(buffer, prices);

    cout  CalcIncome(prices)  endl;
}

void ParseStr(const string& to_parse, vectorint& to_save) {
    string word;
    for (const char c  to_parse) {
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

int CalcIncome(const vectorint& prices) {
    auto buy_price = prices.begin();
    int income = 0;
    while (buy_price != prices.end() - 1 && buy_price != prices.end()) {
        auto sell_price = buy_price + 1;
        int curr_income = sell_price - buy_price;
        int max_curr_income = 0;
        while (sell_price != prices.end()) {
            curr_income = sell_price - buy_price;
            if (max_curr_income  curr_income) {
                break;
            }
            max_curr_income = curr_income;
            sell_price++;
        }

        income += max_curr_income;
        buy_price = sell_price;
    }
    return income;
}
