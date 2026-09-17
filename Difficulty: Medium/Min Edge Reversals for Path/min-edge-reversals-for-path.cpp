class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Original edge
            adj[u].push_back({v, 0});

            // Reversed edge
            adj[v].push_back({u, 1});
        }

        vector<int> dist(n + 1, INT_MAX);
        deque<int> dq;

        dist[src] = 0;
        dq.push_front(src);

        while(!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            for(auto &[v, cost] : adj[u]) {

                if(dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;

                    if(cost == 0)
                        dq.push_front(v);
                    else
                        dq.push_back(v);
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};