// The graph header file

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "edge.h"
#include "node.h"

using namespace std;

struct Graph {
public:
    map<string, Node> graph;

    void addNode(string name){
        Node oneNode;
        oneNode.name = name;
        graph[name] = oneNode;
    };

    void addEdge(string from, string to, double distance){
        Edge newEdge {to, distance};
        graph[from].edges.push_back(newEdge);
    };

    void removeNode(){};

    void printNodes(){
        for(auto& [name, nodes]: graph){
            cout << "From " << name << ": \nhead";
            for(Edge edges: nodes.edges){
                cout << " -> " << edges.destination << "(" << edges.distance << "m)";
            }
            cout << endl;
            cout << endl;
        }
    };

    int noOfNodes(){
        return graph.size();
    };

    Node returnNode(string node){
        return graph[node];
    };

};

#endif
