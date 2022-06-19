#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>

class Graph {
    private:
	    std::vector<std::vector<int> > adj;
	    std::size_t V;
	    bool oriented;

        void DFS_helper(size_t start, std::vector<bool>& visited, std::vector<size_t>& result) const;
        void TopoSort_Tarjan_rec(size_t x, std::vector<size_t>& result, std::vector<size_t>& dist, std::vector<size_t>& color, std::vector<size_t>& path, size_t time) const;

    public:
        Graph();
        Graph(size_t _V, bool _oriented);
        
        void addEdge(size_t start, size_t end);
        void print() const;

        std::vector<size_t> BFS(size_t start) const;
        std::vector<size_t> DFS(size_t start) const;
        std::vector<size_t> TopoSort_Tarjan() const; // Tarjan's Topological Sorting algorithm
        std::vector<size_t> TopoSort_Kahn() const; // Kahn's Topologiacl Sorting algorithm
};

Graph::Graph(): V(0), adj(0), oriented(false) {}

Graph::Graph(size_t V, bool isOriented) : adj(V), V(V), oriented(isOriented)
{}

void Graph::addEdge(size_t start, size_t end) {
	adj[start].push_back(end);
	if (!oriented)
		adj[end].push_back(start);
}

void Graph::print() const {
    std::cout<<"Graph:"<<std::endl;
    for(size_t v = 0; v < adj.size(); v++) {
        std::cout<<"Vertex "<<v<<": ";
        for (size_t i = 0; i< adj[v].size(); i++) {
            std::cout<<adj[v][i]<<" ";
        }
        std::cout<<std::endl;
    }
}

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

// Tarjan's Topological Sorting algorithm

enum Color {
    white,
    gray,
    black
};

void Graph::TopoSort_Tarjan_rec(size_t x, std::vector<size_t>& result, std::vector<size_t>& dist, std::vector<size_t>& color, std::vector<size_t>& path, size_t time) const {
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
    std::vector<size_t> color(V, c);
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



// Need for testing:
void printVector(std::vector<size_t> v) {
    for (size_t i = 0; i < v.size(); i++) {
        std::cout<<v[i]<<" ";
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
            addToSet(set, currentVertex);
            color[currentVertex] = gray;
        }
        else {
            color[currentVertex] = white;
        }
    }
    size_t k=0;
    while(!set.empty()) {
        size_t currentVertex = set.back();
        set.pop_back();
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
        return std::vector<size_t>(0);
    }
    return result;
}