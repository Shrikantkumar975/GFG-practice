class Solution {
public:
    
    int getCount(int n, int d) {
        
        int curr_ans = 0;
        int l = 1, h = n;
        
        while (l <= h) {
            int m = l + (h - l) / 2;
            
            if (isConditionMet(m, d)) {
                curr_ans = m;     // track smallest valid
                h = m - 1;        // search left part
            } else {
                l = m + 1;        // search right part
            }
        }
        
        return curr_ans == 0 ? 0 : n - curr_ans + 1;
    }
    
private:
    
    bool isConditionMet(int x, int d) {
        int temp = x;
        int curr_sum = 0;
        
        while (x > 0) {
            curr_sum += x % 10;
            x /= 10;
        }
        
        return (temp - curr_sum) >= d;
    }
};
