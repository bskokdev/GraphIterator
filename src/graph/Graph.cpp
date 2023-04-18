#include "Graph.h"
#include "iterators/GraphIteratorBFS.h"
#include "iterators/GraphIteratorDFS.h"

Graph::Graph(const std::vector<std::string> &inputLines) {
    // for each line in the input file create an edge
    for (auto &line: inputLines) {
        addEdgeFromInputLine(line);
    }
}

void Graph::addEdgeFromInputLine(std::string inputLine) {
    std::vector<std::string> tokens = Reader::tokenize(inputLine, ' ');

    int source = std::stoi(tokens[0]);
    int destination = std::stoi(tokens[1]);
    addEdge(source, destination);
}

void Graph::addEdge(int source, int destination) {
    adjacencyList[source].push_back(destination);
    adjacencyList[destination].push_back(source);
}

std::pair<int, std::vector<int>> Graph::findLowestValue() {
    std::pair<int, std::vector<int>> lowestValue = std::make_pair(INT_MAX, std::vector<int>());
    for (auto &entry: adjacencyList) {
        if (entry.first < lowestValue.first) {
            lowestValue = entry;
        }
    }
    return lowestValue;
}

const std::unordered_map<int, std::vector<int>> &Graph::getAdjacencyList() const {
    return this->adjacencyList;
}

GraphIteratorBFS Graph::beginBFS() {
    GraphIteratorBFS it(*this);
    it.reset();
    return it;
}

GraphIteratorBFS Graph::endBFS() {
    GraphIteratorBFS it(*this);
    // move the iterator to the end
    while (!it.isEnd()) {
        ++it;
    }
    return it;
}

GraphIteratorDFS Graph::beginDFS() {
    GraphIteratorDFS it(*this);
    it.reset();
    return it;
}

GraphIteratorDFS Graph::endDFS() {
    GraphIteratorDFS it(*this);
    // move the iterator to the end
    while (!it.isEnd()) {
        ++it;
    }
    return it;
}


