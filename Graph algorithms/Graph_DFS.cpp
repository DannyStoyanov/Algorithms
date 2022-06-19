#include "Graph.h"

// Depth First Search - DFS

void Graph::DFS_helper(size_t start, std::vector<bool>& visited, std::vector<size_t>& result) const {
    visited[start] = true;
    result.push_back(start);
    for(size_t i=0; i<adj[start].size(); i++) {
        size_t neighbour = adj[start][i];
        if(!visited[neighbour]) {
            DFS_helper(neighbour, visited, result);
        }
    }
}

std::vector<size_t> Graph::DFS(size_t start) const {
    std::vector<bool> visited(V, false);
    std::vector<size_t> result;
    DFS_helper(start, visited, result);
    return result;
}