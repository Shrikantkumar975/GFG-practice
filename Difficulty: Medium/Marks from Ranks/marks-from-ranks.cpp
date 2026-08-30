class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int currRank = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        
        for(int i=0;i<rank.size();i++){
            pq.push({rank[i],i});
        }
        
        
        vector<int> ans(rank.size());
        
        int i=0;
        while(!pq.empty()){
            auto [a,b] = pq.top();
            
            if(a - currRank <= r[i] - l[i] + 1){
                ans[b] = l[i]-1+a-currRank;
                pq.pop();
            }else{
                currRank += r[i]-l[i]+1;
                i++;
            }
        }
        
        return ans;
        
    }
};