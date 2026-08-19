class Solution {
public:
    long long countLessEqual(vector<int>& arr, long long x) {
        int n = arr.size();
        long long count = 0;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                long long sum = (long long)arr[i] + arr[j] + arr[k];

                if (sum <= x) {
                    count += (k - j);
                    j++;
                } else {
                    k--;
                }
            }
        }

        return count;
    }

    int countTriplets(vector<int>& arr, int l, int r) {
        sort(arr.begin(), arr.end());

        long long ans = countLessEqual(arr, r)
                      - countLessEqual(arr, (long long)l - 1);

        return (int)ans;
    }
};