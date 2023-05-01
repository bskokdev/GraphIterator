#include "../../include/Graph.h"
#include "../../include/GraphIteratorBFS.h"
#include "../../include/GraphIteratorDFS.h"


Graph::Graph() : adjacencyList() {
    this->adjacencyList = unordered_map<int, vector<int>>();
}

Graph::Graph(vector<string> &inputLines) {
    // for each line in the input file create an edge
    for (string &line: inputLines) {
        vector<string> tokens = tokenizeGraphInput(line, ' ');

        int source = stoi(tokens[0]);
        int destination = stoi(tokens[1]);

        adjacencyList[source].push_back(destination);
        adjacencyList[destination].push_back(source);
    }
}

vector<string> Graph::tokenizeGraphInput(string &input, char divider) {
    vector<string> tokens;
    stringstream ss(input);
    string token;
    while (getline(ss, token, divider)) {
        tokens.push_back(token);
    }
    return tokens;
}

pair<int, vector<int>> Graph::findLowestValue() {
    pair<int, vector<int>> lowestValue = make_pair(0, vector<int>());
    for (auto &entry: adjacencyList) {
        if (entry.first < lowestValue.first) {
            lowestValue = entry;
        }
    }
    return lowestValue;
}

const unordered_map<int, vector<int>> &Graph::getAdjacencyList() const {
    return this->adjacencyList;
}
