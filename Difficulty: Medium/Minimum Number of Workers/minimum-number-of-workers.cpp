class Solution {
  public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Step 1: Convert to intervals
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1) {
                int L = max(0, i - arr[i]);
                int R = min(n - 1, i + arr[i]);
                intervals.push_back({L, R});
            }
        }

        // Step 2: Sort intervals by starting point
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int currentEnd = 0;
        int i = 0;

        // Step 3: Greedy coverage
        while(currentEnd < n) {
            int maxReach = -1;

            while(i < intervals.size() && intervals[i].first <= currentEnd) {
                maxReach = max(maxReach, intervals[i].second);
                i++;
            }

            // If no interval can extend coverage
            if(maxReach < currentEnd)
                return -1;

            count++;
            currentEnd = maxReach + 1;
        }

        return count;
    }
};
