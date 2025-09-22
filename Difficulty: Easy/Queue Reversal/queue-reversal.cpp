class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        vector<int> v;
        
        while(!q.empty()){
            int a = q.front();
            q.pop();
            v.push_back(a);
        }
        
        for(int i=v.size()-1;i>=0;i--){
            q.push(v[i]);
        }
    }
};