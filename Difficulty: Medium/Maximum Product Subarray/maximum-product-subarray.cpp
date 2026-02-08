class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = nums[0];
        int suffix = nums[n-1];
        int maxi = max(prefix, suffix);

        for(int i = 1; i < n; i++){
            // prefix side
            if(prefix == 0)
                prefix = nums[i];
            else
                prefix *= nums[i];

            // suffix side
            if(suffix == 0)
                suffix = nums[n-1-i];
            else
                suffix *= nums[n-1-i];

            maxi = max(maxi, max(prefix, suffix));
        }

        return maxi;
    }
};
