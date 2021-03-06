#include "Graph.h"

// Kahn's Topological Sorting algorithm
// Time complexity: O(n+m)
// n - number of vertices, |V| = n
// m - number of edges, |E| = m

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

std::vector<size_t> Graph::TopoSort_Kahn() const {
    std::vector<size_t> set;
    std::vector<Color> color(V);
    std::vector<size_t> arr(V, 0);
    std::vector<size_t> result(V);
    for (size_t u = 0; u < adj.size(); u++) {
        for (size_t v = 0; v < adj[u].size(); v++) {
            size_t neighbour = adj[u][v];
            arr[neighbour]++;
        }
    }
    for(size_t currentVertex=0; currentVertex < adj.size(); currentVertex++) {
        if(arr[currentVertex] == 0) {
            addToSet(set, currentVertex);  // first add source vertices
            color[currentVertex] = gray;
        }
        else {
            color[currentVertex] = white;
        }
    }
    size_t k=0;
    while(!set.empty()) {                  // then we proceed through the dag,
        size_t currentVertex = set.back(); // contrary to Tarjan's algorithm, where we 
        set.pop_back();                    // start from the end nodes and loop backwards
        result[k]=currentVertex;
        k++;
        for(size_t i=0; i < adj[currentVertex].size(); i++) {
            size_t neighbour = adj[currentVertex][i];
            arr[neighbour]--;
            if(arr[neighbour] == 0) {
                addToSet(set, neighbour);
                color[neighbour] = gray;
            }
        }
        color[currentVertex] = black;
    }
    if(k<V) {
        return std::vector<size_t>(0); // condition to determine whether the graph is DAG
    }
    return result;
}