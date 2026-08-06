class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int increments = 0;
        int doubling = 0;
        
        for(int x : arr){
            int doublee =0;
            
            while(x>0){
                if(x&1) increments++;
                
                x/=2;
                
                
                if(x) doublee++;
            }
            
            doubling = max(doublee,doubling);
        }
        
        return increments + doubling;
    }
};