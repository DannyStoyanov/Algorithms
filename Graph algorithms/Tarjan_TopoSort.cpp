#include "Graph.h"

// Tarjan's Topological Sorting algorithm
// Time complexity: O(n+m)
// n - number of vertices, |V| = n
// m - number of edges, |E| = m

void Graph::TopoSort_Tarjan_rec(size_t x, std::vector<size_t>& result, std::vector<size_t>& dist, std::vector<Color>& color, std::vector<size_t>& path, size_t time) const {
    color[x] = gray;
    time++;
    dist[x] = time;
    for(int i=0; i<adj[x].size(); i++) {
        size_t neighbour = adj[x][i];
        if(color[neighbour] == white) {
            path[neighbour] = x;
            TopoSort_Tarjan_rec(neighbour, result, dist, color, path, time);
        }
    }
    color[x] = black;
    time++;
    result.push_back(x);
}

std::vector<size_t>  Graph::TopoSort_Tarjan() const {
    assert(oriented == true);
    Color c = white;
    std::vector<size_t> result;
    std::vector<Color> color(V, c);
    std::vector<size_t> dist(V, 0);
    std::vector<size_t> path(V, -1);
    size_t time=0;
    for(size_t i=0; i < adj.size(); i++) {
        if(color[i] == white) {
            TopoSort_Tarjan_rec(i, result, dist, color, path, time);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}