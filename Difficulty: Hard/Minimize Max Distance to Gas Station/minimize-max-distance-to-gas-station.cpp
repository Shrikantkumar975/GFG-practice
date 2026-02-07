class Solution {
  public:
    bool check(double mid , vector<int> &stations,int K){
        int used=0;
        
        for(int i=1;i<stations.size();i++){
            used += (int)(stations[i]-stations[i-1])/mid;
        }
        
        return used<=K;
    }
  
    double minMaxDist(vector<int> &stations, int K) {
        double low = 0;
        double high = 1e8;
        
        while((high-low) > 1e-6){
            double mid = (low + high)/2.00;
            
            if(check(mid,stations,K)){
                high=mid;
            }else low=mid;
        }
        
        return high;
    }
};