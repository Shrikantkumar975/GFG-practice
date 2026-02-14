class Solution {
  public:
  
    bool isPossible(vector<int>& arr, int k, long long mid) {
        long long currSum = 0;
        int painters = 1;
        
        for (int i = 0; i < arr.size(); i++) {
            
            if (currSum + arr[i] <= mid) {
                currSum += arr[i];
            } 
            else {
                painters++;
                currSum = arr[i];
                
                if (painters > k)
                    return false;
            }
        }
        
        return true;
    }
  
  
    int minTime(vector<int>& arr, int k) {
        
        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;
        
        for (int x : arr)
            high += x;
        
        long long ans = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;   // try smaller time
            } 
            else {
                low = mid + 1;    // need more time
            }
        }
        
        return ans;
    }
};