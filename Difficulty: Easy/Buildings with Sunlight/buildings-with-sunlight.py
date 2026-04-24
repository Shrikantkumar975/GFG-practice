class Solution:
    def visibleBuildings(self, arr):
        maxi=arr[0]
        count=1
        
        for i in range(1,len(arr)):
            if arr[i] >= maxi:
                count+=1
                maxi = arr[i]
    
        return count        