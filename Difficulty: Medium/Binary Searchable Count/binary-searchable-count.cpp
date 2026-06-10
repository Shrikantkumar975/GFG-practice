class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            bool ok = true;

            while(l <= r) {
                int mid = (l + r) / 2;

                if(mid == i) break;

                if(mid < i) {
                    if(arr[mid] >= arr[i]) {
                        ok = false;
                        break;
                    }
                    l = mid + 1;
                } else {
                    if(arr[mid] <= arr[i]) {
                        ok = false;
                        break;
                    }
                    r = mid - 1;
                }
            }

            if(ok) ans++;
        }

        return ans;
    }
};