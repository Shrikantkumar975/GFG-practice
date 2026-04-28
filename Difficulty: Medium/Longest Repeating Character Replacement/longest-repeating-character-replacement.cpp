class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int r=0,l=0,maxLen=0,maxf=0;
        vector<int> hash(26,0);

        while(r<s.size()){
            hash[s[r]-'A']++;
            maxf = max(maxf,hash[s[r]-'A']);

            // while(r-l+1-maxf > k){
            //     hash[s[l]-'A']--;
            //     maxf=0;
            //     for(int i=0;i<26;i++){
            //         maxf = max(maxf,hash[i]);
            //     }
            //     l+=1;
            // }
            if(r-l+1-maxf > k){
                hash[s[l]-'A']--;
                // maxf=0;
                // for(int i=0;i<26;i++){
                //     maxf = max(maxf,hash[i]);
                // }
                l+=1;
            }

            if(r-l+1-maxf <= k){
                maxLen = max(maxLen,r-l+1);
            }
            r++;
        }

        return maxLen;
    }
};