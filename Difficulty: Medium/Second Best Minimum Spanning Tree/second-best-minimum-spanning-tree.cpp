class DSU {
public:
    vector<int> p, r;

    DSU(int n) : p(n), r(n, 0) {
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

class Solution {
public:

    // Run Kruskal but skip one MST edge (skipU, skipV)
    int runKruskal(int n, vector<array<int,3>> &edges, int skipU, int skipV) {
        DSU dsu(n);
        int cost = 0, used = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            // skip this MST edge
            if ((u == skipU && v == skipV) || (u == skipV && v == skipU))
                continue;

            if (dsu.unite(u, v)) {
                cost += w;
                used++;
            }
        }

        if (used != n - 1) return INT_MAX;  // not a valid tree
        return cost;
    }

    int secondMST(int V, vector<vector<int>> &edgesInput) {

        vector<array<int,3>> edges;
        for (auto &e : edgesInput) {
            edges.push_back({e[0], e[1], e[2]});
        }

        // sort by weight
        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b){ return a[2] < b[2]; });

        // build MST
        DSU dsu(V);
        int mstCost = 0;
        vector<array<int,3>> mstEdges;

        for (auto &e : edges) {
            if (dsu.unite(e[0], e[1])) {
                mstCost += e[2];
                mstEdges.push_back(e);
            }
        }

        // try removing each MST edge
        int secondBest = INT_MAX;

        for (auto &e : mstEdges) {
            int newCost = runKruskal(V, edges, e[0], e[1]);
            if (newCost > mstCost && newCost < secondBest)
                secondBest = newCost;
        }

        return (secondBest == INT_MAX ? -1 : secondBest);
    }
};
