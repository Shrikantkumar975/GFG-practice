class Solution {
  public:
    
    int canPlace(vector<int> &stalls,int cow,int dist){
        int cowCount = 1;
        int last = stalls[0];
        
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last >= dist){
                cowCount++;
                last =  stalls[i];
            }
            if(cowCount >= cow) return true;
        }
        return false;
    }
    
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        int ans=-1;
        
        int low = 1;
        int high = stalls[n-1]-stalls[0];
        
        while(low<=high){
            int mid = (low + high)/2;
            
            if(canPlace(stalls,k,mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        return ans;
    }
};