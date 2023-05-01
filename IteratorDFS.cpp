#include "IteratorDFS.h"

IteratorDFS::IteratorDFS(Graph &graph) : graph(graph) {
    this->visited = set<int>();
    this->stack = ::stack < pair<int, vector<int>> > ();
}

void IteratorDFS::reset() {
    // clear the visited set and the stack
    this->visited.clear();
    while (!this->stack.empty()) {
        this->stack.pop();
    }

    pair<int, vector<int>> lowestValueNode = graph.findNodeWithLowestVal();
    this->stack.push(lowestValueNode);
    this->visited.insert(lowestValueNode.first);
}

bool IteratorDFS::isEnd() {
    return this->stack.empty();
}

IteratorDFS &IteratorDFS::next() {
    if (!this->stack.empty()) {
        pair<int, vector<int>> currentNode = this->stack.top();
        this->stack.pop();

        for (int &neighbor: currentNode.second) {
            if (!this->visited.count(neighbor)) {
                this->stack.emplace(*this->graph.getConnectedNodes().find(neighbor));
                this->visited.insert(neighbor);
            }
        }
    }
    // Check for unvisited nodes (for disconnected graphs)
    if (this->stack.empty()) {
        for (auto &node: this->graph.getConnectedNodes()) {
            if (!this->visited.count(node.first)) {
                this->stack.emplace(node);
                this->visited.insert(node.first);
                break;
            }
        }
    }
    return *this;
}

int IteratorDFS::currentKey() {
    return this->stack.top().first;
}
