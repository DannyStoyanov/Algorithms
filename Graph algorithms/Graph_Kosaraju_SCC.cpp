#include "Graph.h"

// Kosaraju Strongly Connected Components (SCC) algorithm
// Time complexity: O(n+m)
// n - number of vertices, |V| = n
// m - number of edges, |E| = m

// Uses 2 DFS calls contrary to Kahn's algorithm (1 DFS call)

void printSet(std::vector<size_t> set) {
    for (size_t i = 0; i < set.size(); i++) {
        std::cout<<set[i]<<" ";
    }
    std::cout<<std::endl;
}

bool contains(std::vector<size_t>& vec, size_t x) {
    for(std::vector<size_t>::iterator it = vec.begin(); it != vec.end(); it++) {
        if(*it == x) {
            return true;
        }
    }
    return false;
}

void addToSet(std::vector<size_t>& set, size_t x) {
    if(!contains(set, x)) {
        set.push_back(x);
    }
}

void Graph::SCC_rec(std::vector<size_t>& set,  size_t currentVertex, std::vector<Color>& color, std::vector<size_t>& dist, size_t time) const {
    color[currentVertex]=gray;
    time++;
    dist[currentVertex]=time;
    addToSet(set, currentVertex);
    for (size_t i = 0; i < adj[currentVertex].size(); i++) {
        size_t neighbour=adj[currentVertex][i];
        if(color[neighbour] == white) {
            SCC_rec(set, neighbour, color, dist, time);
        }
    }
    color[currentVertex]=black;
    time++;
}

void Graph::SCC(std::vector<size_t>& l) const {
    std::vector<size_t> set;
    size_t time=0;
    std::vector<Color> color(V);
    std::vector<size_t> dist(V);
    for (size_t i = 0; i < color.size(); i++) {
        color[i] = white;
    }
    for (size_t i = 0; i < adj.size(); i++) {
        if(color[l[i]] == white) {
            set.clear();
            SCC_rec(set, l[i], color, dist, time);
            printSet(set);
        }
    }
}

Graph Graph::transpose() const {
    Graph result(V, true);
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            result.addEdge(adj[i][j], i);
        }
    }
    return result;
}

void Graph::SCC_Kosaraju() const {
    std::vector<size_t> l=this->TopoSort_Tarjan();
    Graph g=this->transpose();
    g.SCC(l);
}