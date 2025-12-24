class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int count =0 ;
        
        for(int a: arr){
            if(a<=x) count++;
            
        }
        return count;
    }
};