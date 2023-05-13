#include "../../include/GraphIteratorDFS.h"

GraphIteratorDFS::GraphIteratorDFS(Graph &graph) : graph(graph) {
    this->visited = std::set<int>();
    this->stack = std::stack<int>();
}

void GraphIteratorDFS::reset() {
    // clear the visited set and the stack
    this->visited.clear();
    while (!this->stack.empty()) {
        this->stack.pop();
    }

    std::pair<int, std::vector<int>> lowestValue = graph.findLowestValue();
    this->stack.push(lowestValue.first);
    this->visited.insert(lowestValue.first);
}

bool GraphIteratorDFS::isEnd() {
    return this->stack.empty();
}

GraphBaseIterator &GraphIteratorDFS::next() {
    ++(*this);
    return *this;
}

int GraphIteratorDFS::currentKey() {
    return this->stack.top();
}

GraphBaseIterator &GraphIteratorDFS::operator++() {
    if (!this->stack.empty()) {
        int currentNode = this->stack.top();
        this->stack.pop();

        for(int neighbor : this->graph.getAdjacencyList().at(currentNode)) {
            if (!this->visited.count(neighbor)) {
                this->stack.emplace(neighbor);
                this->visited.insert(neighbor);
            }
        }
    }

    if (this->stack.empty()) {
        for (auto &node: this->graph.getAdjacencyList()) {
            if (!this->visited.count(node.first)) {
                this->stack.emplace(node.first);
                this->visited.insert(node.first);
                break;
            }
        }
    }
    return *this;

}

GraphIteratorDFS GraphIteratorDFS::operator++(int i) {
    GraphIteratorDFS tmpIt = *this;
    ++(*this);
    return tmpIt;
}

int GraphIteratorDFS::operator*() {
    return this->currentKey();
}

bool GraphIteratorDFS::operator!=(const GraphBaseIterator &other) {
    auto *other_ptr = dynamic_cast<const GraphIteratorDFS *>(&other);
    if (other_ptr == nullptr) return true;
    return this->stack != other_ptr->stack;
}
