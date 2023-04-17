#ifndef GRAPHMASTERY_GRAPH_H
#define GRAPHMASTERY_GRAPH_H


#include <unordered_map>
#include <vector>
#include <climits>
#include "iterators/GraphIteratorBFS.h"

class GraphIteratorBFS;  // Forward declaration

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

    /**
     * @brief finds the node with the lowest value
     * @return the node with the lowest value
     */
    std::pair<int, std::vector<int>> findLowestValue();

    /**
     * @brief returns an iterator to the beginning of the graph
     * @return graph iterator
     */
    GraphIteratorBFS begin();

    /**
     * @brief returns an iterator to the end of the graph
     * @return graph iterator
     */
    GraphIteratorBFS end();

    // getters and setters
    const std::unordered_map<int, std::vector<int>> &getAdjacencyList() const;
};


#endif //GRAPHMASTERY_GRAPH_H
