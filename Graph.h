#ifndef GRAPHITERATOR_GRAPH_H
#define GRAPHITERATOR_GRAPH_H


#include <unordered_map>
#include <vector>
#include <string>
#include "Reader.h"

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adjacencyList;

    static vector<string> tokenizeGraphInput(string &input, char divider);

public:
    Graph();

    explicit Graph(vector<string> &inputLines);

    pair<int, vector<int>> findLowestValue();

    const unordered_map<int, vector<int>> &getAdjacencyList() const;
};


#endif
