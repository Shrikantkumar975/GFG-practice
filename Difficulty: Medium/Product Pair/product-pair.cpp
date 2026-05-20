#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_set<long long> seen;
        
        for (int x : arr) {
            // Edge Case: If the current element is 0
            if (x == 0) {
                // Since the array size >= 2, any 0 can pair with another element 
                // to make a product of 0.
                if (target == 0) return true;
            } 
            // For non-zero elements
            else {
                // Check if target is perfectly divisible by the current element
                if (target % x == 0) {
                    long long req = target / x;
                    
                    // If the required pair element is already in our set, we found a match
                    if (seen.count(req)) {
                        return true;
                    }
                }
            }
            
            // Add the current element to the set for future pair checks
            seen.insert(x);
        }
        
        return false;
    }
};