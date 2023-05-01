#include "IteratorBFS.h"

IteratorBFS::IteratorBFS(Graph &graph) : graph(graph) {
    this->queue = ::queue<pair<int, vector<int>>>();
    this->visited = set<int>();
}

void IteratorBFS::reset() {
    // clear the queue and visited set
    this->visited.clear();
    while (!this->queue.empty()) {
        this->queue.pop();
    }

    // add the first node to the queue
    pair<int, vector<int>> lowestValueNode = graph.findLowestValue();
    this->queue.push(lowestValueNode);
    this->visited.insert(lowestValueNode.first);
}

bool IteratorBFS::isEnd() {
    return this->queue.empty();
}

IteratorBFS &IteratorBFS::next() {
    // do a single BFS step over the connected component
    if (!this->queue.empty()) {
        pair<int, vector<int>> currentNode = this->queue.front();
        this->queue.pop();

        // add all unvisited neighbors to the queue
        for (int &neighbor: currentNode.second) {
            if (!this->visited.count(neighbor)) {
                this->queue.emplace(*this->graph.getAdjacencyList().find(neighbor));
                this->visited.insert(neighbor);
            }
        }
    }

    // if the queue is empty, add the first unvisited node to the queue (disconnected component found)
    if (this->queue.empty()) {
        for (auto &node: this->graph.getAdjacencyList()) {
            if (!this->visited.count(node.first)) {
                this->queue.emplace(node);
                this->visited.insert(node.first);
                break;
            }
        }
    }

    return *this;
}

int IteratorBFS::currentKey() {
    return this->queue.front().first;
}
