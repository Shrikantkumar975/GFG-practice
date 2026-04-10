class Solution {
public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> smaller(n, -1);
        vector<int> greater(n, -1);

        // Step 1: find smaller elements on left
        int min_index = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[min_index]) {
                min_index = i;
            } else {
                smaller[i] = min_index;
            }
        }

        // Step 2: find greater elements on right
        int max_index = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[max_index]) {
                max_index = i;
            } else {
                greater[i] = max_index;
            }
        }

        // Step 3: find valid triplet
        for (int i = 0; i < n; i++) {
            if (smaller[i] != -1 && greater[i] != -1) {
                return {arr[smaller[i]], arr[i], arr[greater[i]]};
            }
        }

        return {};
    }
};