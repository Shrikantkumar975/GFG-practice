class Solution {
  public:
    void dfs(int i, vector<bool>& v, vector<vector<int>>& stones) {
    if (v[i]) return;
    v[i] = true;

    for (int j = 0; j < stones.size(); j++) {

        // if another stone has same row or 
        // column as this stone then both lie 
        // in the same component
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
            dfs(j, v, stones);
        }
    }
}

int maxRemove(vector<vector<int>>& stones) {
    int n = stones.size();
    
    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; i++) {
        
        // visiting the stone if not visited
        // and finding all the stones lying in 
        // the same component as this stone
        if (!visited[i]) {
            dfs(i, visited, stones);
            components++;
        }
    }

    // atleast 1 stone per component 
    // cannot be removed
    return n - components;
}
};