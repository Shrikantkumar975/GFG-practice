class Solution {
  public:
    class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x) {
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px==py) return;
        if(rank[px]<rank[py]) parent[px]=py;
        else if(rank[px]>rank[py]) parent[py]=px;
        else { parent[py]=px; rank[px]++; }
    }

    bool connected(int x,int y) {
        return find(x)==find(y);
    }
};

int minCostPath(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int total = n*m;

    // Store edges: {weight, cell1, cell2}
    vector<array<int,3>> edges;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int u = i*m + j;
            
            // Only right and down neighbors to avoid duplicates
            if(i+1 < n)
                edges.push_back({
                        abs(mat[i][j]-mat[i+1][j]), u, (i+1)*m+j});
            
            if(j+1 < m) 
                edges.push_back({
                        abs(mat[i][j]-mat[i][j+1]), u, i*m + (j+1)});
        }
    }

    // Sort edges by weight (smallest first)
    sort(edges.begin(), edges.end());

    DSU dsu(total);

    // Connect cells using edges in increasing order
    for(auto &e : edges) {
        int w = e[0], u = e[1], v = e[2];
        dsu.unite(u,v);

        // Check if start and end are connected
        if(dsu.connected(0, total-1))
            return w;
    }
    
    // Only occurs if single cell
    return 0;
}
};
