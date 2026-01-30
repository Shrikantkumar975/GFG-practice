class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int> q1;
        queue<int> q2;
        
        int size = q.size();
        
        for(int i=0;i<size/2;i++){
            q1.push(q.front());
            q.pop();
        }
        size/=2;
        while(size--){
            q2.push(q.front());
            q.pop();
        }
        
        while(!q1.empty() && !q2.empty()){
            q.push(q1.front());
            q.push(q2.front());
            q1.pop();
            q2.pop();
        }
    }
};