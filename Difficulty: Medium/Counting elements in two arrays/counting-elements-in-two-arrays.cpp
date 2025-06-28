class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> v;
    
    // Step 1: Sort b
    sort(b.begin(), b.end());
    
    // Step 2: For each element in a, use upper_bound
    for (int i = 0; i < a.size(); i++) {
        // upper_bound returns iterator to the first element > a[i]
        // So distance from b.begin() gives count of elements <= a[i]
        int count = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        v.push_back(count);
    }
    
    return v;
    }
};