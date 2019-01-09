#include "Graph.h"

// Constructor without any parameters
Graph::Graph() {
    vertex = 0;
    adjacencyMatrix.resize(vertex, vector<int>(vertex));
}

// Constructor with a number of vertices as a parameter
Graph::Graph(int vertex) {
    this->vertex = vertex;
    adjacencyMatrix.resize(vertex, vector<int>(vertex));
}

// Function for input the adjacency matrix
void Graph::inputMatrix() {
    adjacencyMatrix = {
            {0, 7, 9, 0, 0, 14},
            {7, 0, 10, 15, 0, 0},
            {9, 10, 0, 11, 0, 2},
            {0, 15, 11, 0, 6, 0},
            {0, 0, 0, 6, 0, 9},
            {14, 0, 2, 0, 9, 0}
    };
    /*for (int i = 0; i < vertex; i++) {
        cout << "Input the row number " << (i + 1) << " of the adjacency matrix: ";
        for (int j = 0; j < vertex; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }*/
}

// Function for output the adjacency matrix
void Graph::outputMatrix() {
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << setw(8) << left << adjacencyMatrix[i][j];
        }
        cout << endl;
    }
}

// Function for searching for the shortest paths from the specified vertex
vector<int> Graph::findShortestPaths(int vertex) {
    int currentVertex = vertex - 1; // Assign the specified matrix as a current matrix
    vector<int> pathsLength(this->vertex, INT_MAX); // Vector for paths length
    vector<bool> vertexDone(this->vertex, false); // Vector for flags if vertices were reviewed
    pathsLength[currentVertex] = 0; // Length to the specified vertex is 0

    // Error: invalid vertex was inputted
    if (vertex > this->vertex || vertex <= 0) {
        cout << "Error: invalid vertex was inputted" << endl;
        return vector<int>(this->vertex, -1);
    }

    bool done = false;

    while (!done) {
        for (int i = 0; i < this->vertex; i++) {
            if (adjacencyMatrix[currentVertex][i] > 0 && i != currentVertex && !vertexDone[i]) {
                //cout << "Vertex => from " << currentVertex + 1 << " to " << i + 1 << endl;
                int length = pathsLength[currentVertex] + adjacencyMatrix[currentVertex][i]; // Find the length of the new path
                if (length < pathsLength[i]) { // Found path is shorter than previous path
                    pathsLength[i] = length; // Update the length
                }
            }
        }

        vertexDone[currentVertex] = true; // Set the specified vertex as done
        currentVertex = this->findClosestVertex(currentVertex, vertexDone);

        done = checkIfVerticesDone(vertexDone);
    }

    return pathsLength;
}

// Function that searches for the closest vertex to the specified vertex
int Graph::findClosestVertex(int vertex, vector<bool> vertexDone) {
    int min = INT_MAX;
    int index = 0;
    for (int i = 0; i < this->vertex; i++) {
        if (adjacencyMatrix[vertex][i] < min && adjacencyMatrix[vertex][i] > 0 && i != vertex && !vertexDone[i]) {
            min = adjacencyMatrix[vertex][i];
            index = i;
        }
    }
    return index;
}

bool Graph::checkIfVerticesDone(vector<bool> vertexDone) {
    for (int i = 0; i < this->vertex; i++) {
        if (vertexDone[i] == false) { // There's unreviewed vertex
            return false; // Return false
        }
    }
    return true; // All vertices were reviewed
}