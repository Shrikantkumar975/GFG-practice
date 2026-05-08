class Solution {
  public:
  
    bool isValid(string &str) {
        int cnt = 0;
        
        for(char ch : str) {
            if(ch == '(') cnt++;
            else if(ch == ')') {
                cnt--;
                if(cnt < 0) return false;
            }
        }
        
        return cnt == 0;
    }
  
    vector<string> validParenthesis(string &s) {
        
        vector<string> ans;
        unordered_set<string> vis;
        queue<string> q;
        
        q.push(s);
        vis.insert(s);
        
        bool found = false;
        
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            
            if(isValid(curr)) {
                ans.push_back(curr);
                found = true;
            }
            
            // If valid string found at current level,
            // don't generate next level
            if(found) continue;
            
            for(int i = 0; i < curr.size(); i++) {
                
                // Remove only parentheses
                if(curr[i] != '(' && curr[i] != ')')
                    continue;
                
                string next = curr.substr(0, i) + curr.substr(i + 1);
                
                if(!vis.count(next)) {
                    vis.insert(next);
                    q.push(next);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};