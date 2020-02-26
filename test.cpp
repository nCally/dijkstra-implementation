#include <iostream>
#include <string>
#include <vector>
#include "graph.h"
#include "dijkstra.h"

using namespace std;

int main(){
    vector<string> all {"Hype", "Source", "Cat", "Andrenaline"}; // to represent the nodes

    Graph graph;

    for(string node: all)
        graph.addNode(node);

    graph.addEdge("Source", "Andrenaline", 45.3);
    graph.addEdge("Andrenaline", "Cat", 23);
    graph.addEdge("Source", "Cat", 12.9);
    graph.addEdge("Cat", "Source", 12.9);
    graph.addEdge("Hype", "Source", 35.0);

    //graph.printNodes();

    dijkstra(graph, "Cat");

    return 0;
}