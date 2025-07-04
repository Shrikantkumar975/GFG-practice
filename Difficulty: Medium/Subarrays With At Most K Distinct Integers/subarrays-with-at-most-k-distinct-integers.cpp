class Solution {
public:
    int countAtMostK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp; // to store frequency of elements in current window

        int i      = 0;             // left boundary of sliding window
        int j      = 0;             // right boundary of sliding window
        int result = 0;             // total number of valid subarrays

        while (j < n) {
            mp[arr[j]]++;           // include arr[j] in the window

            while (mp.size() > k) { // if distinct elements exceed k, shrink window from left
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) {
                    mp.erase(arr[i]); // remove element with 0 frequency
                }
                i++;                  // move left pointer to right
            }

            result += (j - i + 1);   // count subarrays ending at j with at most k distinct elements
            j++;                     // expand window to the right
        }
        return result;
    }
};
