class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
     int n = mices.size();
    // Sort the arrays
    sort(mices.begin(), mices.end());
    sort(holes.begin(), holes.end());
    
    // Finding max difference between 
    // ith mice and hole 
    int max = 0; 
    for(int i = 0; i < n; ++i)
    {
        if (max < abs(mices[i] - holes[i]))
            max = abs(mices[i] - holes[i]);
    }
    return max;
}
};