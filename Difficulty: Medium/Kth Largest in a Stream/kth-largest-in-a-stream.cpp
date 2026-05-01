class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        
        for(int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
            
            // Keep only k elements
            if(pq.size() > k) {
                pq.pop();
            }
            
            // If less than k elements
            if(pq.size() < k) {
                ans.push_back(-1);
            } else {
                ans.push_back(pq.top()); // kth largest
            }
        }
        
        return ans;
    }
};