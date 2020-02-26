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
    graph.addEdge("Source", "Piits", 12.9);
    graph.addEdge("Source", "Ben", 5.9);
    graph.addEdge("Source", "Ken", 19.87);
    graph.addEdge("Source", "Cat", 4.9);
    graph.addEdge("Cat", "Source", 39);
    graph.addEdge("Hype", "Source", 1);
    graph.addEdge("Ben", "Piits", 12);
    graph.addEdge("Piits", "Hype", 3);
    graph.addEdge("Fly", "Source", 3);

    dijkstra(graph, "Fly");


    //graph.printNodes();

    return 0;
}