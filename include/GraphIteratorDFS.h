#ifndef GRAPHMASTERY_GRAPHITERATORDFS_H
#define GRAPHMASTERY_GRAPHITERATORDFS_H


#include <set>
#include <stack>
#include "Graph.h"

class Graph;

using namespace std;

class GraphIteratorDFS {
private:
    Graph &graph;
    set<int> visited;
    stack<pair<int, vector<int>>> stack;
public:
    explicit GraphIteratorDFS(Graph &graph);

    void reset();

    bool isEnd();

    GraphIteratorDFS &next();

    int currentKey();

    bool operator!=(const GraphIteratorDFS &other);
};


#endif //GRAPHMASTERY_GRAPHITERATORDFS_H
