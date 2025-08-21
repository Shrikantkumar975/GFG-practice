class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int mid){
    int count = 1;
    int last = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - last >= mid) {
            count++;
            last = arr[i];
        }
        if (count == k)
            return true;
    }

    return false;
}

int maxMinDiff(vector<int>& arr, int k){
    // sort the array
    sort(arr.begin(), arr.end());

    // define binary search range
    int low = 0;
    int high = arr.back() - arr.front();
    int answer = 0;

    // binary search to find max valid min-diff
    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, k, mid)) {
            answer = mid;
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    // return the maximum feasible 
    // minimum difference
    return answer;
}

};
