#include "Graph.h"

// Breadth First Search - BFS

std::vector<size_t> Graph::BFS(size_t start) const {
    std::vector<size_t> result;
    std::vector<bool> visited(V, false);
    std::queue<size_t> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        size_t currentVertex = q.front();
        q.pop();
        result.push_back(currentVertex);
        for(size_t i=0; i < adj[currentVertex].size(); i++) {
            size_t neighbour = adj[currentVertex][i];
            if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
    return result;
}