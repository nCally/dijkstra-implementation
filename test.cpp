#include <iostream>
#include <string>
#include <vector>
#include "graph.h"
#include "dijkstra.h"

using namespace std;

int main(){
    vector<string> all {"A", "B", "C", "D"}; // to represent the nodes

    Graph graph;

    for(string node: all)
        graph.addNode(node);

    graph.addEdge("A", "B", 4);
    graph.addEdge("A", "D", 13);

    graph.addEdge("B", "C", 2.5);
    graph.addEdge("C", "B", 2.5);

    graph.addEdge("D", "C", 5.0);
    graph.addEdge("D", "A", 13);

    dijkstra(graph, "A");


    //graph.printNodes();

    return 0;
}