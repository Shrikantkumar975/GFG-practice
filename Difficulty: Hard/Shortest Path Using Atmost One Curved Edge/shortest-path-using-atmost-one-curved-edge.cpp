class Solution {
public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {

        // adjacency list: adj[u] = { {v, w1, w2}, ... }
        vector<vector<array<int,3>>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w1 = e[2];
            int w2 = e[3];

            adj[u].push_back({v, w1, w2});
            adj[v].push_back({u, w1, w2});   // UNDIRECTED graph
        }

        int INF = 1e9;
        vector<vector<int>> dist(V, vector<int>(2, INF));

        // min-heap: {distance, node, usedCurve}
        using State = array<int, 3>;
        priority_queue<State, vector<State>, greater<State>> pq;

        // Start from 'a' without using curved edge
        dist[a][0] = 0;
        pq.push({0, a, 0});

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();

            int d = cur[0];
            int node = cur[1];
            int used = cur[2];

            if (d != dist[node][used]) continue;

            // neighbours
            for (auto &it : adj[node]) {
                int nxt = it[0];
                int w1  = it[1];
                int w2  = it[2];

                // 1) Take straight edge
                if (dist[nxt][used] > d + w1) {
                    dist[nxt][used] = d + w1;
                    pq.push({dist[nxt][used], nxt, used});
                }

                // 2) Take curved edge if not used yet
                if (used == 0) {
                    if (dist[nxt][1] > d + w2) {
                        dist[nxt][1] = d + w2;
                        pq.push({dist[nxt][1], nxt, 1});
                    }
                }
            }
        }

        int ans = min(dist[b][0], dist[b][1]);
        return ans >= INF ? -1 : ans;
    }
};
