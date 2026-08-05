class Solution {
public:
    long long solve(vector<int>& arr, long long x){
        if(x < 0) return 0;

        long long ans = 0, sum = 0;
        int left = 0;

        for(int right = 0; right < arr.size(); right++){
            sum += arr[right];

            while(sum > x){
                sum -= arr[left];
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }

    long long countSubarray(vector<int>& arr, int l, int r) {
        return solve(arr, r) - solve(arr, (long long)l - 1);
    }
};