class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> v;
        queue<string> q;
        
        q.push("1");
        
        while(n--){
            string str = q.front();
            q.pop();
            v.push_back(str);
            
            q.push(str+"0");
            q.push(str+"1");
        }
        
        return v;
    }
};