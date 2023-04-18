#include "Application.h"

#include <utility>

Application::Application(Reader reader) : reader(std::move(reader)) {}

void Application::run() {
    std::vector<std::string> lines = reader.readLines();
    Graph graph(lines);

    // print iterator results
    std::cout << "BFS: ";
    for (auto it = graph.beginBFS(); it != graph.endBFS(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "DFS: ";
    for (auto it = graph.beginDFS(); it != graph.endDFS(); ++it) {
        std::cout << *it << " ";
    }
}