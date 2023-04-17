#ifndef GRAPHMASTERY_GRAPH_H
#define GRAPHMASTERY_GRAPH_H


#include <unordered_map>
#include <vector>
#include <climits>

/**
 * @brief class representing a graph
 * @details the graph is represented as an adjacency list
 */
class Graph {
private:
    std::unordered_map<int, std::vector<int>> adjacencyList;
public:

    /**
     * @brief default constructor for graph
     */
    Graph();

    /**
     * @brief connects two vertices with an edge
     * @param source source node
     * @param destination destination node
     */
    void addEdge(int source, int destination);

    std::pair<int, std::vector<int>> findLowestValue();
};


#endif //GRAPHMASTERY_GRAPH_H
