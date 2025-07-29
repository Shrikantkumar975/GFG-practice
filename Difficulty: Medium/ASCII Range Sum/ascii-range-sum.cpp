class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        vector<int> result;
    vector<int> first(26, -1);
    vector<int> last(26, -1);
    int n = s.size();

    // Track first and last 
    // occurrence of each character
    for (int i = 0; i < n; i++) {
        if (first[s[i] - 'a'] == -1) {
            first[s[i] - 'a'] = i;
        } else {
            last[s[i] - 'a'] = i;
        }
    }

    // Compute ASCII sums 
    // between first and last occurrence
    for (int i = 0; i < 26; i++) {
        if (first[i] != -1 && last[i] != -1) {
            int sum = 0;
            for (int j = first[i] + 1; j < last[i]; j++) {
                sum += (int)s[j];
            }
            if(sum != 0)
            result.push_back(sum);
        }
    }

    return result;
    }
};