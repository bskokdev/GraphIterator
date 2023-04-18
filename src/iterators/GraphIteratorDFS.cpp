#include "GraphIteratorDFS.h"

GraphIteratorDFS::GraphIteratorDFS(Graph &graph) : graph(graph) {
    this->visited = std::set<int>();
    this->stack = std::stack<std::pair<int, std::vector<int>>>();
}

void GraphIteratorDFS::reset() {
    // clear the visited set and the stack
    this->visited.clear();
    while(!this->stack.empty()) {
        this->stack.pop();
    }

    std::pair<int, std::vector<int>> lowestValue = graph.findLowestValue();
    this->stack.push(lowestValue);
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
    return this->stack.top().first;
}

GraphBaseIterator& GraphIteratorDFS::operator++() {
    // Do a single DFS step (over the connected component)
    if(!this->stack.empty()) {
        std::pair<int, std::vector<int>> currentNode = this->stack.top();
        this->stack.pop();

        for (int &neighbor : currentNode.second) {
            if (!this->visited.count(neighbor)) {
                this->stack.emplace(*this->graph.getAdjacencyList().find(neighbor));
                this->visited.insert(neighbor);
            }
        }
    }
    // Check for unvisited nodes (for disconnected graphs)
    if(this->stack.empty()) {
        for(auto &node : this->graph.getAdjacencyList()) {
            if(!this->visited.count(node.first)) {
                this->stack.emplace(node);
                this->visited.insert(node.first);
                break;
            }
        }
    }
    return *this;
}

GraphBaseIterator& GraphIteratorDFS::operator++(int i) {
    auto tmpIt = *this;
    ++(*this);
    return tmpIt;
}

int GraphIteratorDFS::operator*() {
    return this->currentKey();
}

bool GraphIteratorDFS::operator!=(const GraphBaseIterator &other) {
    auto* other_ptr = dynamic_cast<const GraphIteratorDFS*>(&other);
    if(other_ptr == nullptr) return true;
    return this->stack != other_ptr->stack;
}
