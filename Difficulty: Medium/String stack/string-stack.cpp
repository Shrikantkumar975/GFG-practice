class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        
    // Start from the last character of both strings
    int i = pat.size() - 1, j = tar.size() - 1;
    
    while (i >= 0 and j >= 0) {
        
        // If characters don’t match, simulate a deletion 
        // by skipping previous character in 'pat'
        if (pat[i] != tar[j]) {
            i -= 2;
        } 
        // If characters match, move both
        // pointers to the previous character
        else {
            i--;
            j--;
        }
    }

    // If we have successfully matched 
    // all characters of 'tar', return true
    return j < 0;
}
};