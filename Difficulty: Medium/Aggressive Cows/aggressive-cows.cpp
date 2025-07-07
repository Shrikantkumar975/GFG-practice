// User function Template for C++

class Solution {
  public:
    bool canWePlace(vector<int>&arr,int cows,int dist){
        int cowsCount = 1,last = arr[0];
        
        for(int i=1;i<arr.size();i++){
            if(arr[i] - last >= dist){
                cowsCount++;
                last = arr[i];
            }
            if(cowsCount >= cows) return true;
        }
        
        return false;
    }

    int aggressiveCows(vector<int> &arr, int cows) {

        sort(arr.begin(),arr.end());
        
        int low = 1, high = arr[arr.size()-1] - arr[0];
        int ans=-1;
        
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(canWePlace(arr,cows,mid)==true){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return ans;
        
    }
};