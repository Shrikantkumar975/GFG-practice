// User function template for C++

class Solution {
  public:
    void multiply(vector<int> &v, int n){
        int size=v.size();
        int carry = 0;
        for(int i=0;i<size;i++){
            int num = v[i]*n+carry;
            v[i]=num%10;
            carry=num/10;
        }
        while(carry){
            v.push_back(carry%10);
            carry/=10;
        }
    }
    
    vector<int> factorial(int n) {
        // code here
        vector<int> v;
        v.push_back(1);
        
        if(n==1) return v;
        
        for(int i=2;i<=n;i++){
            multiply(v,i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};