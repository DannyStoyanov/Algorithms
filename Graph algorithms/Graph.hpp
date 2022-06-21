#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
#include <stack>

enum Color {
    white,
    gray,
    black
};

class Graph {
    private:
	    std::vector<std::vector<size_t> > adj;
	    std::size_t V;
	    bool oriented;

        void DFS_helper(size_t start, std::vector<bool>& visited, std::vector<size_t>& result) const;
        void TopoSort_Tarjan_rec(size_t x, std::vector<size_t>& result, std::vector<size_t>& dist, std::vector<Color>& color, std::vector<size_t>& path, size_t time) const;
        void SCC_rec(std::vector<size_t>& set, size_t currentVertex, std::vector<Color>& color, std::vector<size_t>& dist, size_t time) const;
        void SCC(std::vector<size_t>& l) const;
        bool hasCycle_helper(size_t currentVertex, std::vector<bool>& visited, std::vector<bool>& stack) const;
        void SCC_Tarjan_helper(size_t currentVertex, std::vector<size_t>& disc, std::vector<size_t>& low, std::stack<size_t>& st, std::vector<bool>& stackMember) const;
    public:
        Graph();
        Graph(size_t _V, bool _oriented);
        
        void addEdge(size_t start, size_t end);
        void print() const;

        std::vector<size_t> BFS(size_t start) const;
        std::vector<size_t> DFS(size_t start) const;
        std::vector<size_t> TopoSort_Tarjan() const; // Tarjan's Topological Sorting algorithm
        std::vector<size_t> TopoSort_Kahn() const; // Kahn's Topologiacl Sorting algorithm
        void SCC_Kosaraju() const;
        void SCC_Tarjan() const;
        Graph transpose() const;
        bool hasCycle() const;
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

void printSet(std::vector<size_t> set) {
    for (size_t i = 0; i < set.size(); i++) {
        std::cout<<set[i]<<" ";
    }
    std::cout<<std::endl;
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

void Graph::SCC_Tarjan_helper(size_t currentVertex, std::vector<size_t>& disc, std::vector<size_t>& low, std::stack<size_t>& st, std::vector<bool>& stackMember) const {
    static size_t time=0;
    disc[currentVertex]=low[currentVertex]=++time;
    st.push(currentVertex);
    stackMember[currentVertex]=true;
    std::vector<const size_t>::iterator it;
    for (it = adj[currentVertex].begin(); it != adj[currentVertex].end(); it++) {
        size_t neighbour = *it;
        if(disc[neighbour] == -1) {
            SCC_Tarjan_helper(neighbour, disc, low, st, stackMember);
            low[currentVertex] = std::min(low[currentVertex], low[neighbour]);
        }
        else if(stackMember[neighbour] == true) {
            low[currentVertex] = std::min(low[currentVertex], disc[neighbour]);
        }
    }
    size_t x=0;
    if(low[currentVertex] == disc[currentVertex]) {
        while(st.top() != currentVertex) {
            x = st.top();
            std::cout<<x<<" ";
            stackMember[x]=false;
            st.pop();
        }
        x = st.top();
        std::cout<<x<<'\n';
        stackMember[x]=false;
        st.pop();
    }
}

void Graph::SCC_Tarjan() const {
    std::vector<size_t> disc(V, SIZE_T_MAX);
    std::vector<size_t> low(V, SIZE_T_MAX);
    std::vector<bool> stackMember(V, false);
    std::stack<size_t> st;
    for (size_t i = 0; i < V; i++) {
        if(disc[i] == SIZE_T_MAX) {
            SCC_Tarjan_helper(i, disc, low, st, stackMember);
        }
    }
}