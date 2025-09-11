class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n <= 1) return 0;          // already at the end
        if (arr[0] == 0) return -1;    // cannot move anywhere

        int jumps = 1;      // we will need at least one jump
        int maxReach = arr[0];  // farthest index reachable
        int steps = arr[0];     // steps left in current jump

        for (int i = 1; i < n; i++) {
            // if we reached the last element
            if (i == n - 1) return jumps;

            // update farthest reach
            maxReach = max(maxReach, i + arr[i]);

            steps--; // use a step

            if (steps == 0) {  // we need another jump
                jumps++;
                if (i >= maxReach) return -1; // cannot move further
                steps = maxReach - i;  // reset steps for new jump
            }
        }
        return -1; // should not reach here
    }
};
