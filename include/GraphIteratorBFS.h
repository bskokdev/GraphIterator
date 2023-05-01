#ifndef GRAPHMASTERY_GRAPHITERATORBFS_H
#define GRAPHMASTERY_GRAPHITERATORBFS_H

#include <set>
#include <queue>
#include "Graph.h"

using namespace std;

class Graph;

class GraphIteratorBFS {
private:
    Graph &graph;
    set<int> visited;
    queue<pair<int, vector<int>>> queue;
public:
    explicit GraphIteratorBFS(Graph &graph);

    void reset();

    bool isEnd();

    GraphIteratorBFS &next();

    int currentKey();

    bool operator!=(const GraphIteratorBFS &other);
};


#endif //GRAPHMASTERY_GRAPHITERATORBFS_H
