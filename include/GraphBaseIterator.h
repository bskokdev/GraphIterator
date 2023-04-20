#ifndef GRAPHMASTERY_GRAPHBASEITERATOR_H
#define GRAPHMASTERY_GRAPHBASEITERATOR_H

#include <memory>

/**
 * @brief class representing a base iterator for a graph
 */
class GraphBaseIterator {
    /**
     * @brief resets the iterator to the beginning
     */
    virtual void reset() = 0;

    /**
     * @brief checks if the iterator is at the end
     * @return true if the iterator is at the end, false otherwise
     */
    virtual bool isEnd() = 0;

    /**
     * @brief increments the iterator (same as operator++)
     * @return the iterator
     */
    virtual GraphBaseIterator &next() = 0;

    /**
     * @brief gets the current key of the iterator
     * @return value of the current key
     */
    virtual int currentKey() = 0;

    /**
     * @brief increments the iterator (prefix)
     * @return the iterator
     */
    virtual GraphBaseIterator &operator++() = 0;

    /**
     * @brief increments the iterator (postfix)
     * @return the iterator
     */
    virtual GraphBaseIterator &operator++(int i) = 0;

    /**
     * @brief dereferences the iterator
     * @return the value of the iterator
     */
    virtual int operator*() = 0;

    /**
     * @brief checks if the iterator is not equal to another iterator
     * @param other the other iterator
     * @return true if the iterators are not equal, false otherwise
     */
    virtual bool operator!=(const GraphBaseIterator &other) = 0;
};


#endif //GRAPHMASTERY_GRAPHBASEITERATOR_H
