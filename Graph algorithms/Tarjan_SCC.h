#include "Graph.h"

// Tarjan Strongly Connected Components (SCC) algorithm
// Time complexity: O(n+m)
// n - number of vertices, |V| = n
// m - number of edges, |E| = m

// Uses single DFS call contrary to Kosaraju's algorithm (2 DFS calls)

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