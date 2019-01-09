#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>
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
    void findShortestPaths(int);
    int findClosestVertex(int, int, vector<bool>);
};


#endif //DIJKSTRA_GRAPH_H
