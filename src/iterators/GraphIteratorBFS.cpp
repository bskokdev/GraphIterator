#include "GraphIteratorBFS.h"

GraphIteratorBFS::GraphIteratorBFS(Graph& graph) : graph(graph) {
    this->queue = std::queue<std::pair<int, std::vector<int>>>();
    this->visited = std::set<int>();
}

void GraphIteratorBFS::reset() {
    // clear the queue and visited set
    this->visited.clear();
    while(!this->queue.empty()) {
        this->queue.pop();
    }

    // add the first node to the queue
    std::pair<int, std::vector<int>> lowestValueNode = graph.findLowestValue();
    this->queue.push(lowestValueNode);
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
    return this->queue.front().first;
}

GraphIteratorBFS &GraphIteratorBFS::operator++() {
    // do a single BFS step over the connected component
    if (!this->queue.empty()) {
        std::pair<int, std::vector<int>> currentNode = this->queue.front();
        this->queue.pop();

        for (int &neighbor : currentNode.second) {
            if (!this->visited.count(neighbor)) {
                this->queue.emplace(*this->graph.getAdjacencyList().find(neighbor));
                this->visited.insert(neighbor);
            }
        }
    }

    // check for unvisited nodes (for disconnected graphs)
    if(this->queue.empty()) {
        for(auto &node : this->graph.getAdjacencyList()) {
            if(!this->visited.count(node.first)) {
                this->queue.emplace(node);
                this->visited.insert(node.first);
                break;
            }
        }
    }

    return *this;
}

std::shared_ptr<GraphBaseIterator> GraphIteratorBFS::operator++(int i) {
    // create a copy of the iterator
    auto tmpIt = std::make_shared<GraphIteratorBFS>(*this);
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
    auto* other_ptr = dynamic_cast<const GraphIteratorBFS*>(&other);
    if(other_ptr == nullptr) return true;
    return this->queue != other_ptr->queue;
}
