class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> v;
        deque<int> dq;
        
        int i=0;
        
        while(i<arr.size()){
            
            if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
            
            while(!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();
            
            dq.push_back(i);
            
            if(i>=k-1)
            v.push_back(arr[dq.front()]);
            
            i++;
        }
        
        return v;
    }
};