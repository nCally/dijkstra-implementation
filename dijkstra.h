/*
Implementation of the Dijkstra's algorithm
*/

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <string>
#include "graph.h"
#include "table.h"

using namespace std;

// the reference to the graph should be passed to this dijstra's implementation
string dijkstra(Graph& graph, string startNode){
    // NO. 1
    vector<string> visited {}; // after every iteration of the graph map keys... add to visited so, we don't go back to same node again
    

    //NO. 2. table pair - would keep details of values from visited nodes
    Table board {};

    int indexNode {0}; // This is where to start in iterating the nodes on the graph.

     // The current node should be a pair of string - for node name and the number is carries
    currentNodeType currentNode { make_pair(startNode, 0) };// At first current node is equal to the start node... subsequently, as the for loop ends current node is changed.

    do {
        map<string, Node>::iterator it = graph.graph.begin();

        while(it != graph.graph.end()){        
            // Find which node is the current node to use to do the edges iteration
            if(it -> first == currentNode.first){
                // do stuffs
                for(Edge edge: it -> second.edges){
                    // check if a particular node already exists in the table_pair map structure
                    if(board.exists(edge.destination)){
                        // meaning it exists
                        // do a push back to the vector of the pair
                        board.push(edge, currentNode, visited);
                    } else {
                        // that means if it doesn't exist
                        // add it to the booard by passing the EDGE(distance and node name)
                        board.createAndPush(edge, currentNode);
                    }
                }

                // The end;
                // add node to visited
                visited.push_back(it -> first);

            }
            
            //cout << "When a loop is done " << currentNode.first << endl;
            //cout << "The current node " << currentNode.first << endl;

            it++;
        }

        // update the current node... with the lowest distance node in the board table.
        currentNode = board.lowestUnvisited(visited);
        
        indexNode++;

    } while(indexNode < graph.graph.size()); 

    // make the start node 0
    board.table[startNode] = make_pair(0, startNode);
    
    // to see the nodes and details added to the board table
    map<string, entryPair>::iterator board_it = board.table.begin();
    while(board_it != board.table.end()){
        cout << board_it -> first << ": " << board_it ->second.first << " from (" << board_it ->second.second << ")" << endl;
        
        board_it++;
    }


    // get the initial node
    /* Node theNode = graph.returnNode(startNode);
    cout << "The name " << theNode.name << endl;
    vector<Edge> nodeEdges = theNode.edges;
    for(Edge node: nodeEdges){
        cout << node.distance << " to " << node.destination << endl;
    } */

    return "";
};

#endif
