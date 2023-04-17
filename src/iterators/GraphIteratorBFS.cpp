#include "GraphIteratorBFS.h"

GraphIteratorBFS::GraphIteratorBFS(Graph &graph) : graph(graph) {
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
