class Solution {
  public:
    
    vector<int> lps(vector<int>& b) {
        int m = b.size();
        vector<int> p(m, 0);

        int j = 0;

        for(int i = 1; i < m; i++) {
            while(j > 0 && b[i] != b[j]) {
                j = p[j - 1];
            }

            if(b[i] == b[j]) {
                j++;
            }

            p[i] = j;
        }

        return p;
    }

    vector<int> search(vector<int> &a, vector<int> &b) {
        
        int n = a.size();
        int m = b.size();

        vector<int> p = lps(b);
        vector<int> ans;

        int j = 0;

        for(int i = 0; i < n; i++) {

            while(j > 0 && a[i] != b[j]) {
                j = p[j - 1];
            }

            if(a[i] == b[j]) {
                j++;
            }

            if(j == m) {
                ans.push_back(i - m + 1);
                j = p[j - 1];
            }
        }

        return ans;
    }
};