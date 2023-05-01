#ifndef GRAPHMASTERY_GRAPH_H
#define GRAPHMASTERY_GRAPH_H


#include <unordered_map>
#include <vector>
#include <string>
#include <map>
#include "Reader.h"

using namespace std;

class Graph {
private:
    map<int, vector<int>> connectedNodes;

    static vector<int> tokenizeGraphInput(string &input, char divider);

public:
    Graph();

    explicit Graph(vector<string> &input);

    pair<int, vector<int>> findNodeWithLowestVal();

    const map<int, vector<int>> &getConnectedNodes() const;
};


#endif //GRAPHMASTERY_GRAPH_H
