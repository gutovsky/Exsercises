#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UniqueActivities {
public:
    void Add(string activity) {
        for (auto it = activities_.begin(); it != activities_.end(); ++it) {
            if (*it == activity) {
                return;
            }
        }
        activities_.push_back(activity);
    }
    void Print() {
        for (auto it = activities_.begin(); it != activities_.end(); ++it) {
            cout << *it << endl;
        }
    }
private:
    vector<string> activities_;
};

int main()
{
    string buffer;
    getline(cin, buffer);

    int activities_num = stol(buffer, nullptr, 10);

    UniqueActivities activities_list;
    for (int i = 0; i < activities_num; ++i) {
        getline(cin, buffer);
        activities_list.Add(buffer);
    }
    activities_list.Print();

}
