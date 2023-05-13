#include "../../include/GraphIteratorBFS.h"

GraphIteratorBFS::GraphIteratorBFS(Graph &graph) : graph(graph) {
    this->queue = std::queue<int>();
    this->visited = std::set<int>();
}

void GraphIteratorBFS::reset() {
    // clear the queue and visited set
    this->visited.clear();
    while (!this->queue.empty()) {
        this->queue.pop();
    }

    // add the first node to the queue
    std::pair<int, std::vector<int>> lowestValueNode = graph.findLowestValue();
    this->queue.push(lowestValueNode.first);
    this->visited.insert(lowestValueNode.first);
}

bool GraphIteratorBFS::isEnd() {
    return this->queue.empty();
}

GraphBaseIterator &GraphIteratorBFS::next() {
    ++(*this);
    return *this;
}

int GraphIteratorBFS::currentKey() {
    return this->queue.front();
}

GraphBaseIterator &GraphIteratorBFS::operator++() {
    // do a single BFS step over the connected component
    if (!this->queue.empty()) {
        int currentNode = this->queue.front();
        this->queue.pop();

        for (int neighbor : this->graph.getAdjacencyList().at(currentNode)) {
            if (!this->visited.count(neighbor)) {
                this->queue.emplace(neighbor);
                this->visited.insert(neighbor);
            }
        }
    }

    // check for unvisited nodes (for disconnected graphs)
    if (this->queue.empty()) {
        for (auto &node: this->graph.getAdjacencyList()) {
            if (!this->visited.count(node.first)) {
                this->queue.emplace(node.first);
                this->visited.insert(node.first);
                break;
            }
        }
    }

    return *this;
}

GraphIteratorBFS GraphIteratorBFS::operator++(int i) {
    // create a copy of the iterator
    GraphIteratorBFS tmpIt = *this;
    // increment the original iterator
    ++(*this);
    // return the copy
    return tmpIt;
}

int GraphIteratorBFS::operator*() {
    return this->currentKey();
}

bool GraphIteratorBFS::operator!=(const GraphBaseIterator &other) {
    // cast to GraphIteratorBFS
    auto *other_ptr = dynamic_cast<const GraphIteratorBFS *>(&other);
    if (other_ptr == nullptr) return true;
    return this->queue != other_ptr->queue;
}
