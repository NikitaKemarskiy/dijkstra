#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    int verticesNumber; // Number of vertices
    int vertex; // Vertex for searching the shortest paths

    cout << "Input the number of vertices: ";
    cin >> verticesNumber;
    cout << "Input the vertex: ";
    cin >> vertex;
    Graph graph(verticesNumber);

    graph.inputMatrix();
    graph.outputMatrix();

    vector<int> pathsLength = graph.findShortestPaths(1);

    for (int i = 0; i < pathsLength.size(); i++) {
        cout << vertex << " - " << i + 1 << ": " << pathsLength[i] << endl;
    }

    return 0;
}