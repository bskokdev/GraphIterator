#ifndef GRAPHITERATOR_GRAPHITERATORDFS_H
#define GRAPHITERATOR_GRAPHITERATORDFS_H


#include <set>
#include <stack>
#include "Graph.h"

using namespace std;

class IteratorDFS {
private:
    Graph &graph;
    set<int> visited;
    stack<pair<int, vector<int>>> stack;
public:
    explicit IteratorDFS(Graph &graph);

    void reset();

    bool isEnd();

    IteratorDFS &next();

    int currentKey();
};


#endif
