#include "Graph.h"

// Detect Cycle in Directed Graph
// Time complexity: O(n+m)
// n - number of vertices, |V| = n
// m - number of edges, |E| = m

bool Graph::hasCycle_helper(size_t currentVertex, std::vector<bool>& visited, std::vector<bool>& stack) const {
    if(!visited[currentVertex]) {
        visited[currentVertex] = true;
        stack[currentVertex] = true;
        for (size_t i = 0; i < adj[currentVertex].size(); i++) {
            size_t neighbour = adj[currentVertex][i];
            if(!visited[neighbour] &&  hasCycle_helper(neighbour, visited, stack)) {
                return true;
            }
            else if(stack[neighbour]) {
                    return true;
            }
        }
    }
    stack[currentVertex] = false;
    return false;
}

bool Graph::hasCycle() const {
    assert(this->oriented == true);
    std::vector<bool> visited(V, false);
    std::vector<bool> stack(V, false);
    for (size_t i = 0; i < V; i++) {
        if(!visited[i] && hasCycle_helper(i, visited, stack)) {
            return true;
        }
    }
    return false;
}