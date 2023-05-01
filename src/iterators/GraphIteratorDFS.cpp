#include "../../include/GraphIteratorDFS.h"

GraphIteratorDFS::GraphIteratorDFS(Graph &graph) : graph(graph) {
    this->visited = set<int>();
    this->stack = ::stack < pair<int, vector<int>> > ();
}

void GraphIteratorDFS::reset() {
    // clear the visited set and the stack
    this->visited.clear();
    while (!this->stack.empty()) {
        this->stack.pop();
    }

    pair<int, vector<int>> lowestValue = graph.findLowestValue();
    this->stack.push(lowestValue);
    this->visited.insert(lowestValue.first);
}

bool GraphIteratorDFS::isEnd() {
    return this->stack.empty();
}

GraphIteratorDFS &GraphIteratorDFS::next() {
    if (!this->stack.empty()) {
        pair<int, vector<int>> currentNode = this->stack.top();
        this->stack.pop();

        for (int &neighbor: currentNode.second) {
            if (!this->visited.count(neighbor)) {
                this->stack.emplace(*this->graph.getAdjacencyList().find(neighbor));
                this->visited.insert(neighbor);
            }
        }
    }
    // Check for unvisited nodes (for disconnected graphs)
    if (this->stack.empty()) {
        for (auto &node: this->graph.getAdjacencyList()) {
            if (!this->visited.count(node.first)) {
                this->stack.emplace(node);
                this->visited.insert(node.first);
                break;
            }
        }
    }
    return *this;
}

int GraphIteratorDFS::currentKey() {
    return this->stack.top().first;
}

bool GraphIteratorDFS::operator!=(const GraphIteratorDFS &other) {
    auto *other_ptr = dynamic_cast<const GraphIteratorDFS *>(&other);
    if (other_ptr == nullptr) return true;
    return this->stack != other_ptr->stack;
}
