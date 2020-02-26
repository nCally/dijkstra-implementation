// To represent the Nodes in the graph
#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using namespace std;

struct Node {
    string name;
    vector<Edge> edges {};
};

#endif