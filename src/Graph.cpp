#include "Graph.h"

Graph::Graph() {
    adjacencyList = std::unordered_map<int, std::vector<int>>();
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
