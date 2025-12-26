class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int missing = 0;
        int current = 1;
        int i = 0;
        
        while (true) {
            if (i < arr.size() && arr[i] == current) {
                i++; // number exists
            } else {
                missing++; // number is missing
                if (missing == k) return current;
            }
            current++;
        }
    }
};
