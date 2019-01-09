#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Graph {
private:
    int vertex;
    vector<vector<int>> adjacencyMatrix;
public:
    Graph();
    Graph(int);
    void inputMatrix();
    void outputMatrix();
};


#endif //DIJKSTRA_GRAPH_H
