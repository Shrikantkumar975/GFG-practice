class Solution {
  public:
    
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    
    int solve(int from, int to, int d) {
        int step = 1;
        int curr_from = from;
        int curr_to = 0;
        
        while(curr_from != d && curr_to != d) {
            int temp = min(curr_from, to - curr_to);
            
            curr_to += temp;
            curr_from -= temp;
            step++;
            
            if(curr_from == d || curr_to == d) break;
            
            if(curr_from == 0) {
                curr_from = from;
                step++;
            }
            
            if(curr_to == to) {
                curr_to = 0;
                step++;
            }
        }
        
        return step;
    }
    
    int minSteps(int m, int n, int d) {
        
        // Not possible
        if(d > max(m, n)) return -1;
        if(d % gcd(m, n) != 0) return -1;
        
        // Try both ways
        return min(solve(m, n, d), solve(n, m, d));
    }
};