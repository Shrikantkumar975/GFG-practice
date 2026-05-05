class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        int n = arr.size();
        long long result = 0;

        // iterate over all bits (0 to 30 is enough for constraints)
        for (int bit = 0; bit < 31; bit++) {
            long long count1 = 0;

            // count numbers having this bit set
            for (int num : arr) {
                if (num & (1 << bit)) {
                    count1++;
                }
            }

            long long count0 = n - count1;

            // contribution of this bit
            result += count1 * count0 * (1LL << bit);
        }

        return result;
    }
};