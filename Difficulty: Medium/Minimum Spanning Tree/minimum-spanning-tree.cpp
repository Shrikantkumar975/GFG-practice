class Solution {
  public:
    vector<int> parent, rank;

    int find(int v) {
        if (parent[v] == v)
            return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    int spanningTree(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        rank.assign(V, 0);

        for (int i = 0; i < V; i++)
            parent[i] = i;

        // Sort edges by weight
        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        int mstWeight = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (find(u) != find(v)) {
                Union(u, v);
                mstWeight += w;
            }
        }

        return mstWeight;
    }
};
