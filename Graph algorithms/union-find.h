#include <iostream>
#include <vector>

// Time complexity: O(logn)
// Space complexity: O(n)

// path compression technique
size_t find(std::vector<size_t>& parent, size_t x) {
    // find root and make root as parent of i (path
    // compression)
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}
 
// uses union by rank
void Union(std::vector<size_t>& parent, size_t x, size_t y) {
    if (parent[x] < parent[y]) {
        parent[find(parent, y)] = find(parent, x);
    }
    else {
        parent[find(parent, x)] = find(parent, y);
    }
}