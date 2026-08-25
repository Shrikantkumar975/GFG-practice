class Solution {
  public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();

        // pos[x] = position of value x in arr
        vector<int> pos(n + 1);

        for (int i = 0; i < n; i++) {
            pos[arr[i]] = i;
        }

        // Find the longest consecutive sequence
        // whose positions are already increasing.
        int longest = 1;
        int curr = 1;

        for (int x = 2; x <= n; x++) {
            if (pos[x] > pos[x - 1]) {
                curr++;
            } else {
                curr = 1;
            }

            longest = max(longest, curr);
        }

        return n - longest;
    }
};