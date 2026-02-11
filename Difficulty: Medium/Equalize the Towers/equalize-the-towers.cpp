class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({heights[i], cost[i]});
        }
        
        sort(v.begin(), v.end());
        
        long long totalCost = 0;
        for(int i = 0; i < n; i++)
            totalCost += v[i].second;
        
        long long cumulative = 0;
        int targetHeight = 0;
        
        for(int i = 0; i < n; i++) {
            cumulative += v[i].second;
            if(cumulative >= (totalCost + 1) / 2) {
                targetHeight = v[i].first;
                break;
            }
        }
        
        long long answer = 0;
        for(int i = 0; i < n; i++) {
            answer += 1LL * abs(v[i].first - targetHeight) * v[i].second;
        }
        
        return answer;
    }
};
