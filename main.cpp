#include <iostream>
#include "src/Graph.h"

int main() {
    Graph graph;

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    for(auto it = graph.begin(); it != graph.end(); it++) {
        std::cout << it.currentKey() << std::endl;
    }
    return 0;
}
