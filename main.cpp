#include <iostream>
#include "Reader.h"
#include "Graph.h"
#include "IteratorDFS.h"
#include "IteratorBFS.h"

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

    IteratorDFS dfsIt(graph);
    cout << "DFS: ";
    for (dfsIt.reset(); !dfsIt.isEnd(); dfsIt.next()) {
        cout << dfsIt.currentKey() << " ";
    }

    cout << endl;

    IteratorBFS bfsIt(graph);
    cout << "DFS: ";
    for (bfsIt.reset(); !bfsIt.isEnd(); bfsIt.next()) {
        cout << bfsIt.currentKey() << " ";
    }
    return 0;
}
