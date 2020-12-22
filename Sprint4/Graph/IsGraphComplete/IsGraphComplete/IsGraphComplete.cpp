#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> GetNumberOfVertexesAndEdges();
vector<vector<bool>> InitAdjacencyMatrix(int vertexes);
bool IsGraphComplete(int vertexes, int edges);
vector<int> GetEdge();
vector<int> ParseStr(const string& to_parse);

int main()
{
    vector<int> sizes = GetNumberOfVertexesAndEdges();
    if (IsGraphComplete(sizes[0], sizes[1])) {
        cout << "YES"s << endl;
    }
    else {
        cout << "NO"s << endl;
    }
}

bool IsGraphComplete(int vertexes, int edges) {
    if (edges < (vertexes * (vertexes - 1)) / 2) {
        return false;
    }

    vector<vector<bool>> adjacency = InitAdjacencyMatrix(vertexes);

    for (int i = 0; i < edges; i++) {
        vector<int> edge = GetEdge();
        adjacency[edge[0] - 1][edge[1] - 1] = true;
        adjacency[edge[1] - 1][edge[0] - 1] = true;
    }
    for (int i = 0; i < vertexes; i++) {
        for (int j = 0; j < vertexes; j++) {
            if (i != j && !adjacency[i][j]) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<bool>> InitAdjacencyMatrix(int vertexes) {
    vector<vector<bool>> adjacency;
    for (int i = 0; i < vertexes; i++) {
        adjacency.push_back({});
        for (int j = 0; j < vertexes; j++) {
            adjacency[i].push_back(false);
        }
    }
    return adjacency;
}

vector<int> GetEdge() {
    string str;
    getline(cin, str);
    return ParseStr(str);
}

vector<int> GetNumberOfVertexesAndEdges() {
    string str;
    getline(cin, str);
    return ParseStr(str);
}

vector<int> ParseStr(const string& to_parse) {
    string word;
    vector<int> to_save;
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
    return to_save;
}