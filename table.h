#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

// how the current node pair exists
typedef pair<string, double> currentNodeType;
typedef pair<double, string> entryPair; // This is the pair of entry added to the board table

struct Table{
    map<string, entryPair> table;

    void createAndPush(Edge edge, currentNodeType index){
        entryPair newPair {make_pair(edge.distance, index.first)};
        table[edge.destination] = newPair; // this registers a new destination in the table.
    };

    /* This push method will
    1. Checks if a node has already been visited. If it has already been visited, skip the push and don't do anything.
    2. Add the current node number to the number on the edge, then compare which distance is smaller. If the new distance is smaller, replace what is already on the vector for that node, else just leave the previous distance and don't do any thing there. */
    void push(Edge edge, currentNodeType currentNode, vector<string>& visited){
        // will do a check of which is larger or not before adding to the map list
        if(find(visited.begin(), visited.end(), edge.destination) == visited.end()){
            // the above condition means that the node has not been visited
            
            double sumDistance { currentNode.second + edge.distance }; // the edge's distance plus the current nodes distance. this is done so we can compare and know which is lesser.

            // since the node already exists in the table..., get the pair registered to the node and compare
            if(sumDistance < table[edge.destination].first){
                table[edge.destination] = make_pair(sumDistance, currentNode.first);
            }
        }
    };

    bool exists(string node){
        if( table.find(node) == table.end() ){ return false; } else { return true; }
    };

    currentNodeType lowestUnvisited(vector<string>& visited){
        //

        map<string, entryPair> unvisitedFromTable {};
        map<string, entryPair>::iterator table_it = table.begin();
        while(table_it != table.end()){
            if(find(visited.begin(), visited.end(), table_it -> first) == visited.end()){
                // means if node has not been visited.
                // add to a new map
                unvisitedFromTable[table_it ->first] = table_it -> second;
            }
            table_it++;
        }

        // from unvisited map, find the key that has the lowest distance in the entryPair
        entryPair smallest = make_pair(numeric_limits<double>::infinity(), "");
        map<string, entryPair>::iterator unvisited_it = unvisitedFromTable.begin();

        while(unvisited_it != unvisitedFromTable.end()){
            if(unvisited_it ->second.first < smallest.first){
                
                smallest = make_pair(unvisited_it ->second.first, unvisited_it ->first);
            }
            unvisited_it++;
        }

        return make_pair(smallest.second, smallest.first);

    };
};


#endif