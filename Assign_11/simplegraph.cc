/*
 * Eriq Walker
 * z1908120
 * CSCI-340-2
 * 
 * I certify that this is my own work and where appropriate an extension
 *  of the starter code provided for the addignment.
 * 
 * */

#include "simplegraph.h"

#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

//Globals
list<int> travel;
list<int> order;
vector<bool> visited;
vector<pair<int,int>> edge;

int main(int argc, char** argv) {
  if (argc < 2) {
    cerr << "args: input-file-name\n";
    return 1;
  }

  Graph g(argv[1]);

  g.Print();

  g.Traverse();

  return 0;
}

//Graph class functions
//constructor
Graph::Graph(const char* filename) {
    ifstream is;
    is.open(filename);
    char temp;
    list<int> templist;
    is >> size;
    for (int i = 0; i < Getsize(); i++) {
        is >> temp;
        labels.push_back(temp);
        visited.push_back(false);
    }
    
    for (int i = 0; i < Getsize(); i++) {
        is >> temp;
        for (int j = 0; j < Getsize(); j++) {
            is >> temp;
            templist.push_back(temp-'0');
        }
        adj_list.push_back(templist);
        templist.clear();
    }
}

//destructor
Graph::~Graph() {
    adj_list.clear();
    labels.clear();
}

//getter
int  Graph::Getsize() const { return size; }

//traversal that calls Depthfirst from a given node
void Graph::Traverse() { 
    visited = *new vector<bool>(size, false);
    
    for (int i = 0; i < Getsize(); i++) {
        if (!visited[i]) Depthfirst(i);
    }
    
    cout <<"------- traverse of graph ------\n";
    
    for (auto it = order.begin(); it != order.end(); it++) cout << labels[*it] << " ";
    cout << endl;

    for (unsigned i = 0; i < edge.size(); i++) {
        cout << "(" << labels[edge[i].first] << ", " 
             << labels[edge[i].second] << ") ";
    }
    cout << endl;
    cout << "--------- end of traverse -------\n\n";
}

//prints the graph's adj list
void Graph::Print() const {
    cout << "\nNumber of vertices in the graph: " << Getsize() << endl << endl;
    cout << "-------- graph -------";

    for (unsigned i = 0; i < adj_list.size(); i++) {
        cout << '\n' << labels[i] << ": ";
        for (unsigned j = 0; j < adj_list[i].size(); j++) {
            auto it = adj_list[i].begin();
            advance(it, j);
            if (*it == 1) cout << labels[j] << ", ";
        }
    }
    
    cout << "\n------- end of graph ------\n\n";
}

//does a depth first traversal of the graph
void Graph::Depthfirst(int index) {
    if (!visited[index]) order.push_back(index);
    visited[index] = true;
    int i = 0;

    for (auto it = adj_list[index].begin(); it != adj_list[index].end(); it++) {
        if (*it == 1 && !visited[i]) {
            edge.push_back(make_pair(index, i));
            Depthfirst(i);
            i++;
        }
    }
}
