#include <iostream>
#include <vector>
#include <queue>

class Graph {
    private:
	    std::vector<std::vector<int> > adj;
	    std::size_t V;
	    bool oriented;

        void DFS_helper(size_t start, std::vector<bool>& visited, std::vector<size_t>& result) const;
    public:
        Graph();
        Graph(size_t _V, bool _oriented);
        
        void addEdge(size_t start, size_t end);
        void print() const;

        std::vector<size_t> BFS(size_t start) const;
        std::vector<size_t> DFS(size_t start) const;
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