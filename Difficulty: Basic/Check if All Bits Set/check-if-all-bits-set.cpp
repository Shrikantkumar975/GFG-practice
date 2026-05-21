class Solution {
  public:
    bool isBitSet(int n) {
        if(n==0) return false;
        // code here
        while(n){
            if(n%2==0) return false;
            
            n/=2;
        }
        
        return true;
    }
};