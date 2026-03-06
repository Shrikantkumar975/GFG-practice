class Solution {
public:
    string minWindow(string &s, string &p) {
        
        vector<int> need(26,0);
        
        for(char c : p)
            need[c-'a']++;
        
        int left = 0;
        int count = p.size();
        
        int start = 0;
        int minLen = INT_MAX;
        
        for(int right = 0; right < s.size(); right++)
        {
            if(need[s[right]-'a'] > 0)
                count--;
                
            need[s[right]-'a']--;
            
            while(count == 0)
            {
                if(right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }
                
                need[s[left]-'a']++;
                
                if(need[s[left]-'a'] > 0)
                    count++;
                    
                left++;
            }
        }
        
        if(minLen == INT_MAX)
            return "";
            
        return s.substr(start, minLen);
    }
};