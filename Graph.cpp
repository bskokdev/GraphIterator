#include "Graph.h"

Graph::Graph() {
    this->connectedNodes = map<int, vector<int>>();
}

Graph::Graph(vector<string> &input) {
    for (int i = 0; i < input.size(); ++i) {
        vector<int> tokens = tokenizeGraphInput(input[i], ' ');

        int first = tokens[0];
        int second = tokens[1];

        connectedNodes[first].push_back(second);
        connectedNodes[second].push_back(first);
    }
}

vector<int> Graph::tokenizeGraphInput(string &input, char divider) {
    vector<int> tokens(input.size());
    stringstream ss(input);
    string token;
    while (getline(ss, token, divider)) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}

pair<int, vector<int>> Graph::findNodeWithLowestVal() {
    pair<int, vector<int>> lowestValueNode = {0, vector<int>()};
    for (auto &node: connectedNodes) {
        if (node.first < lowestValueNode.first) {
            lowestValueNode = node;
        }
    }
    return lowestValueNode;
}

const map<int, vector<int>> &Graph::getConnectedNodes() const {
    return this->connectedNodes;
}
