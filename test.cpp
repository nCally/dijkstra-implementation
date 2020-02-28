#include <iostream>
#include <string>
#include <vector>
#include "graph.h"
#include "dijkstra.h"

using namespace std;

int main(){
    vector<string> all {"Chidubem", "Martins", "Adah", "Somto", "Dangote"}; // nodes

    Graph graph;

    for(string node: all)
        graph.addNode(node);

    graph.addEdge("Adah", "Chidubem", 4);
    graph.addEdge("Martins", "Chidubem", 4);
    graph.addEdge("Adah", "Martins", 7.8);
    graph.addEdge("Martins", "Adah", 7.8);
    graph.addEdge("Adah", "Somto", 1.5);
    graph.addEdge("Somto", "Adah", 1.5);
    graph.addEdge("Somto", "Dangote", 2);
    graph.addEdge("Dangote", "Somto", 2);
    graph.addEdge("Dangote", "Martins", 3);

    dijkstra(graph, "Adah");


    //graph.printNodes();

    return 0;
}