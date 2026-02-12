class Solution {
public:

    bool canMake(vector<int>& arr, int n, int k, int w, long long target) {
        
        vector<long long> diff(n + 1, 0);   // difference array
        long long totalWaterUsed = 0;
        long long currAdded = 0;

        for (int i = 0; i < n; i++) {
            
            currAdded += diff[i];  // apply previous water effect
            long long currentHeight = arr[i] + currAdded;

            if (currentHeight < target) {
                
                long long need = target - currentHeight;
                totalWaterUsed += need;

                if (totalWaterUsed > k)
                    return false;

                currAdded += need;

                if (i + w < n)
                    diff[i + w] -= need;
            }
        }

        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        
        int n = arr.size();
        
        long long low = *min_element(arr.begin(), arr.end());
        long long high = low + k;
        long long ans = low;

        while (low <= high) {
            
            long long mid = low + (high - low) / 2;

            if (canMake(arr, n, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
