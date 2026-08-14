class Solution {
    public:
        void generateSums(vector<long long>& a, int idx, long long sum,
                          vector<long long>& res, long long x) {
            if (sum > x) return;

            if (idx == a.size()) {
                res.push_back(sum);
                return;
            }

            // Don't take a[idx]
            generateSums(a, idx + 1, sum, res, x);

            // Take a[idx]
            generateSums(a, idx + 1, sum + a[idx], res, x);
        }

        bool isPossible(vector<int>& arr, int s, int x) {
            if (x == 0) return true;

            vector<long long> nums;

            long long total = s;
            if (s <= x)
                nums.push_back(s);

            for (int a : arr) {
                long long next = total + a;

                if (next > x)
                    break;

                nums.push_back(next);
                total += next;
            }

            int n = nums.size();
            int mid = n / 2;

            vector<long long> left(nums.begin(), nums.begin() + mid);
            vector<long long> right(nums.begin() + mid, nums.end());

            vector<long long> leftSums, rightSums;

            generateSums(left, 0, 0, leftSums, x);
            generateSums(right, 0, 0, rightSums, x);

            sort(rightSums.begin(), rightSums.end());

            for (long long sum : leftSums) {
                if (sum > x) continue;

                long long need = x - sum;

                if (binary_search(rightSums.begin(), rightSums.end(), need))
                    return true;
            }

            return false;
        }
    };