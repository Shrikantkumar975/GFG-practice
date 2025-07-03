// User function Template for Java//User function Template for Java
class Solution {
    
    public void fun(int[] arr,ArrayList<Integer> res,int index,int currSum){
        if(index == arr.length){
            res.add(currSum);
            return;
        }
        
        fun(arr,res,index+1,currSum+arr[index]);
        
        fun(arr,res,index+1,currSum);
    }
    
    public ArrayList<Integer> subsetSums(int[] arr) {
        // code here
        ArrayList<Integer> res = new ArrayList<>();
        
        fun(arr,res,0,0);
        
        return res;
    }
}