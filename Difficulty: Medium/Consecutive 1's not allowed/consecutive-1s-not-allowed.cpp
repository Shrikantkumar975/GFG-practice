class Solution {
  public:
    int countStrings(int n) {
        // code here
        vector<int> v(45,0);
        if(n==1) return 2;
        v[1]=2;
        v[2]=3;
        
        for(int i=3;i<=n;i++){
            v[i]=v[i-1]+v[i-2];
        }
        
        return v[n];
    }
};