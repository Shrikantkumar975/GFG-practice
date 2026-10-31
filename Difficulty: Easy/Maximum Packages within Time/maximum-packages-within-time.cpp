
class Solution {
public:
    int maxPackages(vector<int>& arr, int totalTime) {
        int n = arr.size();

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (i >= totalTime) {
                sum -= arr[i - totalTime];
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};
