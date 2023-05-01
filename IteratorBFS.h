#ifndef GRAPHMASTERY_GRAPHITERATORBFS_H
#define GRAPHMASTERY_GRAPHITERATORBFS_H

#include <set>
#include <queue>
#include "Graph.h"

using namespace std;

class IteratorBFS {
private:
    Graph &graph;
    set<int> visited;
    queue<pair<int, vector<int>>> queue;
public:
    explicit IteratorBFS(Graph &graph);

    void reset();

    bool isEnd();

    IteratorBFS &next();

    int currentKey();

    bool operator!=(const IteratorBFS &other);
};


#endif //GRAPHMASTERY_GRAPHITERATORBFS_H
