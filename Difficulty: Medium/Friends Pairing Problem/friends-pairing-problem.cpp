class Solution {
  public:
    int countFriendsPairings(int n) {
        if(n<=2) return n;
        
        int n1 = 1;
        int n2 = 2;
        
        int curr = 3;
        
        while(curr<=n){
            int temp = n2;
            n2 = n2 + (curr - 1)*n1;
            n1=temp;
            curr++;
        }
        
        return n2;
    }
};
