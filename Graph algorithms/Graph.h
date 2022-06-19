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

