class Solution:
    def canSplit(self, arr):
        sum=0;
        for i in arr:
            sum+=i;
        
        curr=0;
        for i in arr:
            curr+=i
            if curr == sum - curr:
                return True
            
        
        return False