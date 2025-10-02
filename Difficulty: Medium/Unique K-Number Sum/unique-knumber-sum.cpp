class Solution {
  public:
    void findCombinations(int n, int k, vector<int>& subVector,
                      vector<vector<int>>& res, int last) {
                          
    // Base case: if exact sum and exact count achieved
    if (n == 0 && k == 0) {
        res.push_back(subVector);
        return;
    }

    // If sum or count becomes negative, backtrack
    if (n < 0 || k < 0)
        return;

    // Try numbers from 'last' to 9
    for (int i = last; i <= 9; i++) {
    
        // Choose the number
        subVector.push_back(i);              
        findCombinations(n - i, k - 1, subVector, res, i + 1);
        
        // Backtrack
        subVector.pop_back();                 
    }
}

// Function to generate and print all combinations
vector<vector<int>> combinationSum(int n, int k) {
    
    // Check if combination is impossible
    if (n < k || n > 9 * k) {
        return {};
    }
    
    vector<int> subVector;  
    
    vector<vector<int>> res;            

    findCombinations(n, k, subVector, res, 1); 
    
    return res;
}
};