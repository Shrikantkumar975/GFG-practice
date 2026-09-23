class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();

        vector<int> left(n), right(n);

        // Maximum pyramid height possible ending at i
        left[0] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = min(arr[i], left[i - 1] + 1);
        }

        // Maximum pyramid height possible starting at i
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(arr[i], right[i + 1] + 1);
        }

        long long sum = 0;
        int maxHeight = 0;

        for (int x : arr) {
            sum += x;
        }

        // Peak height at i is limited by both sides
        for (int i = 0; i < n; i++) {
            int height = min(left[i], right[i]);
            maxHeight = max(maxHeight, height);
        }

        // Pyramid 1..h..1 has sum = h^2
        long long maximumKept = 1LL * maxHeight * maxHeight;

        return sum - maximumKept;
    }
};