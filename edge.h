// To represent the Egdes in the graph
//
// The edges just has the weight, which is represented
// here as the distance, and the destination which should
// be a type of Node representing where the edge terminates.
//

#ifndef EDGE_H
#define EDGE_H

#include <string>

using namespace std;

struct Edge {
    double distance;
    string destination;
    Edge(string dest, double dist){
        distance = dist;
        destination = dest;
    };
};
#endif