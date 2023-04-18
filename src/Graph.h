#ifndef GRAPHMASTERY_GRAPH_H
#define GRAPHMASTERY_GRAPH_H


#include <unordered_map>
#include <vector>
#include <climits>
#include "iterators/GraphIteratorBFS.h"
#include "iterators/GraphIteratorDFS.h"

// Forward declaration
class GraphIteratorBFS;
class GraphIteratorDFS;

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
     * @brief returns an iterator to the beginning of the graph (BFS)
     * @return graph BFS iterator
     */
    GraphIteratorBFS beginBFS();

    /**
     * @brief returns an iterator to the end of the graph (BFS)
     * @return graph BFS iterator
     */
    GraphIteratorBFS endBFS();

    /**
     * @brief returns an iterator to the beginning of the graph (DFS)
     * @return graph DFS iterator
     */
    GraphIteratorDFS beginDFS();

    /**
     * @brief returns an iterator to the end of the graph (DFS)
     * @return graph DFS iterator
     */
    GraphIteratorDFS endDFS();

    // getters and setters
    const std::unordered_map<int, std::vector<int>> &getAdjacencyList() const;
};


#endif //GRAPHMASTERY_GRAPH_H
