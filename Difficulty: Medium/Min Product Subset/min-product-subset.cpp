class Solution {
public:
    int mini = INT_MAX;

    void generate(vector<int>& arr, int i, int curr, bool taken) {
        if (i == arr.size()) {
            if (taken)
                mini = min(mini, curr);
            return;
        }

        // Take current element
        generate(arr, i + 1, curr * arr[i], true);

        // Don't take current element
        generate(arr, i + 1, curr, taken);
    }

    int minProd(vector<int>& arr) {
        mini = INT_MAX;   // reset
        generate(arr, 0, 1, false);
        return mini;
    }
};