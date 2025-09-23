class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        vector<int> v;
        
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        
        for(int i=v.size()-1;i>=0;i--){
            q.push(v[i]);
        }
    }
};