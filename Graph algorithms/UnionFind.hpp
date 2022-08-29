#include <iostream>
#include <vector>

// Time complexity: O(logn)
// Space complexity: O(n)

struct UnionFind {
private:
    std::vector<size_t> parent;
public:
    UnionFind(size_t n): parent(n) {
        for (size_t i = 0; i < n; i++) {
            parent[i] = i;
        }
    };

    // path compression technique
    size_t find(size_t x) {
        // find root and make root as parent of i (path
        // compression)
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // uses union by rank
    void unionFind(size_t x, size_t y) {
        if (parent[x] < parent[y]) {
            parent[find(y)] = find(x);
        }
        else {
            parent[find(x)] = find(y);
        }
    }
};