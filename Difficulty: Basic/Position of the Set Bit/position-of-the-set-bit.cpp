class Solution {
  public:
    int findPosition(int n) {
        // code here
        if((n&n-1)!=0) return -1;
        
        int a=0;
        while(n){
            a++;
            n/=2;
        }
        
        return a;
    }
};