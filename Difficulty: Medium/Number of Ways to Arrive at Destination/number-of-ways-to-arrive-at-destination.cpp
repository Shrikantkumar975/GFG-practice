class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {

        const int MOD = 1e9 + 7;

        // build adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});   // undirected (GFG problem)
        }

        vector<int> dist(n, INT_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, 0});  // {time, node}

        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int t = p.first;
            int u = p.second;

            if (t > dist[u]) continue;

            for (auto &pr : adj[u]) {
                int v = pr.first;
                int w = pr.second;

                int nt = t + w;

                if (nt < dist[v]) {
                    dist[v] = nt;
                    ways[v] = ways[u];
                    pq.push({nt, v});
                }
                else if (nt == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};
