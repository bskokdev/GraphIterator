#ifndef GRAPHMASTERY_GRAPHITERATORBFS_H
#define GRAPHMASTERY_GRAPHITERATORBFS_H

#include <set>
#include <queue>
#include "../Graph.h"
#include "GraphBaseIterator.h"

/**
 * @brief class representing a breadth first search iterator
 */
class GraphIteratorBFS : public GraphBaseIterator {
private:
    Graph& graph;
    std::set<int> visited;
    std::queue<std::pair<int, std::vector<int>>> queue;
public:
    // delete the default constructor
    GraphIteratorBFS() = delete;

    /**
     * @brief constructor
     * @param graph Graph to iterate over
     */
    explicit GraphIteratorBFS(Graph &graph);

    /**
     * @brief resets the iterator to the beginning
     * @see GraphBaseIterator::reset()
     */
    void reset() override;

    /**
     * @brief increments the iterator
     * @see GraphBaseIterator::operator++()
     */
    GraphIteratorBFS& operator++() override;

    /**
     * @brief dereferences the iterator
     * @see GraphBaseIterator::operator*()
     */
    int operator*() override;

    /**
     * @brief checks if the iterator is not equal to another iterator
     * @see GraphBaseIterator::operator!=()
     */
    bool operator!=(const GraphBaseIterator& other) override;
};


#endif //GRAPHMASTERY_GRAPHITERATORBFS_H
