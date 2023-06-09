#ifndef GRAPHITERATOR_GRAPHITERATORDFS_H
#define GRAPHITERATOR_GRAPHITERATORDFS_H


#include <set>
#include <stack>
#include "Graph.h"
#include "GraphBaseIterator.h"

class Graph;

/**
 * @brief class representing a depth first search iterator
 */
class GraphIteratorDFS : public GraphBaseIterator {
private:
    Graph &graph;
    std::set<int> visited;
    std::stack<int> stack;
public:
    /**
     * @brief constructor
     * @param graph Graph to iterate over
     */
    explicit GraphIteratorDFS(Graph &graph);

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
    GraphBaseIterator &next() override;

    /**
     * @brief gets the current key of the iterator
     * @see GraphBaseIterator::currentKey()
     */
    int currentKey() override;

    /**
     * @brief increments the iterator (prefix)
     * @see GraphBaseIterator::operator++()
     */
    GraphBaseIterator &operator++() override;

    /**
     * @brief increments the iterator (postfix)
     * @see GraphBaseIterator::operator++(int)
     */
    GraphIteratorDFS operator++(int i);

    /**
     * @brief dereferences the iterator
     * @see GraphBaseIterator::operator*()
     */
    int operator*() override;

    /**
     * @brief checks if the iterator is not equal to another iterator
     * @see GraphBaseIterator::operator!=()
     */
    bool operator!=(const GraphBaseIterator &other) override;
};


#endif //GRAPHITERATOR_GRAPHITERATORDFS_H
