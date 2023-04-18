#ifndef GRAPHMASTERY_GRAPHITERATORBFS_H
#define GRAPHMASTERY_GRAPHITERATORBFS_H

#include <set>
#include <queue>
#include "../Graph.h"
#include "GraphBaseIterator.h"

class Graph;

/**
 * @brief class representing a breadth first search iterator
 */
class GraphIteratorBFS : public GraphBaseIterator {
private:
    Graph& graph;
    std::set<int> visited;
    std::queue<std::pair<int, std::vector<int>>> queue;
public:
    /**
     * @brief constructor
     * @param graph Graph to iterate over
     */
    explicit GraphIteratorBFS(Graph& graph);

    /**
     * @brief resets the iterator to the beginning
     * @see GraphBaseIterator::reset()
     */
    void reset() override;

    /**
     * @brief checks if the iterator is at the end
     * @see GraphBaseIterator::isEnd()
     */
    bool isEnd() override;

    /**
     * @brief increments the iterator
     * @see GraphBaseIterator::next()
     */
    GraphBaseIterator& next() override;

    /**
     * @brief gets the current key of the iterator
     * @see GraphBaseIterator::currentKey()
     */
    int currentKey() override;

    /**
     * @brief increments the iterator (prefix)
     * @see GraphBaseIterator::operator++()
     */
    GraphIteratorBFS& operator++() override;

    /**
     * @brief increments the iterator (postfix)
     * @see GraphBaseIterator::operator++(int)
     */
    GraphBaseIterator& operator++(int) override;

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
