class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        
        if(n==0) return 0;
        // code here
        int x = towerOfHanoi(n-1,from,aux,to);
        
        x++;
        
        x+= towerOfHanoi(n-1,aux,to,from);
        
        return x;
    }
};