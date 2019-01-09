#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    int vertex; // Number of vertices

    cout << "Input the number of vertices: ";
    cin >> vertex;
    Graph graph(vertex);

    graph.inputMatrix();
    graph.outputMatrix();

    graph.findShortestPaths(1);

    return 0;
}