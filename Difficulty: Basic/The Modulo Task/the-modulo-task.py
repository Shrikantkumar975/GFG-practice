class Solution:
    def modTask(self, N):
        # This is the O(1) mathematical solution
        # It replaces the entire loop and works for N = 10^18
        return (N // 2) + 1