#include <iostream>
#include "Graph.h"

int main() {
    Graph graph;

    graph.addEdge(1, 2);
    graph.addEdge(3,4);
    graph.addEdge(5,6);
    graph.addEdge(6,8);
    for(auto it = graph.beginBFS(); it != graph.endBFS(); it++) {
        std::cout << it.currentKey() << std::endl;
    }
    return 0;
}
