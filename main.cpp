#include <iostream>
#include "Reader.h"
#include "Graph.h"
#include "IteratorDFS.h"
#include "IteratorBFS.h"

using namespace std;

int main(int argc, char **argv) {
    string file = argv[1];
    if (argc != 2) {
        cout << "Naval file" << endl;
        return 1;
    }
    Reader reader(file);

    vector<string> input = reader.readLines();
    Graph graph(input);

    IteratorDFS dfsIt(graph);
    cout << "DFS: ";
    for (dfsIt.reset(); !dfsIt.isEnd(); dfsIt.next()) {
        cout << dfsIt.currentKey() << " ";
    }

    cout << endl;

    IteratorBFS bfsIt(graph);
    cout << "BFS: ";
    for (bfsIt.reset(); !bfsIt.isEnd(); bfsIt.next()) {
        cout << bfsIt.currentKey() << " ";
    }
    return 0;
}
