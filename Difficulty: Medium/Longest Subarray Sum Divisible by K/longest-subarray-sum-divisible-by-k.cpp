
class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        int sum = 0;
        int ans = 0;

        // Remainder 0 before starting
        mp[0] = -1;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // Handle negative numbers
            int rem = ((sum % k) + k) % k;

            if (mp.find(rem) != mp.end()) {
                ans = max(ans, i - mp[rem]);
            }
            else {
                // Store only the first occurrence
                mp[rem] = i;
            }
        }

        return ans;
    }
};
