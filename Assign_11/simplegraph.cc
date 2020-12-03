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
#include <string>

using namespace std;

//globals
list<int> trav;
vector<bool> visited;
list<int> order;
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

//Graph functions
//constructor
Graph::Graph(const char* filename) {
    ifstream cin(filename);

    char   line;
    char   temp1;
    int    temp2;
    string temp3;
    cin >> size;
    getline(cin, temp3);

    for(int i = 0; i < Getsize(); i++) {
        cin >> line;
        labels.push_back(line);
        visited.push_back(false);
    }

    for(int i = 0; i < Getsize(); i++) {
        cin >> temp1;
        for(int j = 0; j < Getsize(); j++) {
            cin >> temp2;
            trav.push_back(temp2);
        }
        adj_list.push_back(trav);
        trav.erase(trav.begin(), trav.end());
    }
    cin.close();
}

//descructor
Graph::~Graph() {
    adj_list.clear();
    labels.clear();
}

//getter
int Graph::Getsize() const { return size; }

void Graph::Traverse() {
    visited = *new vector<bool>(size, false);

    for(int i = 0; i < size; i++) {
        if(!visited[i])
        Depthfirst(i);
    }

    cout << "------- traverse of graph ------\n";

    for(auto it = order.begin(); it != order.end(); it++) {
        cout << labels[*it] << " ";
    }
    cout << endl;

    for(unsigned i = 0; i < edge.size(); i++) {
        cout << "(" << labels[edge[i].first] << ", ";
        cout << labels[edge[i].second] << ") ";
    }
    cout << "\n--------- end of traverse -------" << "\n\n";
}

void Graph::Print() const {
    cout << "\nNumber of vertices in the graph: " << size;
    cout << "\n\n-------- graph -------";

    for (unsigned i = 0; i < adj_list.size(); i++) {
        cout << "\n" << labels[i] << ": ";
        for (unsigned j = 0; j < adj_list[i].size(); j++) {
            auto it = adj_list[i].begin();
            advance(it, j);
            if (*it == 1) {
                cout << labels[j] << ", ";
            }
        }
    }

    cout << "\n------- end of graph ------\n\n";
}

void Graph::Depthfirst(int v) {
    if(!visited[v])
    order.push_back(v);

    visited[v] = true;
    int i = 0;
    
    for(auto it = adj_list[v].begin(); it != adj_list[v].end(); it++) {
        if(!visited[i] && *it == 1) {
            edge.push_back(make_pair(v, i));
            Depthfirst(i);
        }
        i++;
    }
}
