#include "Graph.h"

Graph::Graph() {
    vertex = 0;
    adjacencyMatrix.resize(vertex, vector<int>(vertex));
}

Graph::Graph(int vertex) {
    this->vertex = vertex;
    adjacencyMatrix.resize(vertex, vector<int>(vertex));
}

void Graph::inputMatrix() {
    for (int i = 0; i < vertex; i++) {
        cout << "Input the row number " << (i + 1) << " of the adjacency matrix: ";
        for (int j = 0; j < vertex; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }
}

void Graph::outputMatrix() {
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << setw(8) << left << adjacencyMatrix[i][j];
        }
        cout << endl;
    }
}

