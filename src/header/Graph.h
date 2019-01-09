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
    vector<int> findShortestPaths(int);
    int findClosestVertex(int, vector<bool>);
    bool checkIfVerticesDone(vector<bool>);
};


#endif //DIJKSTRA_GRAPH_H
