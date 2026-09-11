class Solution {
  public:
    int sameMod(vector<int> &arr) {
        int g = 0;

        for(int i = 1; i < arr.size(); i++) {
            g = gcd(g, abs(arr[i] - arr[0]));
        }

        // All elements are equal
        if(g == 0)
            return -1;

        int ans = 0;

        // Count divisors of g
        for(int i = 1; i * i <= g; i++) {
            if(g % i == 0) {
                ans++;

                if(i != g / i)
                    ans++;
            }
        }

        return ans;
    }
};