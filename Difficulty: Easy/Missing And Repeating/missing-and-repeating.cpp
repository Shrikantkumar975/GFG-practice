class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        
        long long S = 0, Sq = 0;
        for (long long x : arr) {
            S += x;
            Sq += 1LL * x * x;
        }
        
        long long S_actual = n * (n + 1) / 2;
        long long Sq_actual = n * (n + 1) * (2 * n + 1) / 6;
        
        long long diff = S - S_actual;              // R - M
        long long sqDiff = Sq - Sq_actual;          // R^2 - M^2 = (R - M)(R + M)
        
        long long sum = sqDiff / diff;              // R + M
        
        long long R = (diff + sum) / 2;
        long long M = sum - R;
        
        return {(int)R, (int)M};
    }
};