#include <iostream>
#include "../include/Reader.h"
#include "../include/Graph.h"
#include "../include/GraphIteratorDFS.h"
#include "../include/GraphIteratorBFS.h"

using namespace std;

int main(int argc, char *argv[]) {
    string filePath = argv[1];
    if (filePath.empty() || argc != 2) {
        cout << "Naval file" << endl;
        return 1;
    }
    Reader reader(filePath);

    vector<string> lines = reader.readLines();
    Graph graph(lines);

    GraphIteratorDFS dfsIt(graph);
    cout << "DFS: ";
    for (dfsIt.reset(); !dfsIt.isEnd(); dfsIt.next()) {
        cout << dfsIt.currentKey() << " ";
    }

    cout << endl;

    GraphIteratorBFS bfsIt(graph);
    cout << "DFS: ";
    for (bfsIt.reset(); !bfsIt.isEnd(); bfsIt.next()) {
        cout << bfsIt.currentKey() << " ";
    }
    return 0;
}
