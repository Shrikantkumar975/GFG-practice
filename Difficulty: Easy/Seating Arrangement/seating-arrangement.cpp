class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n = seats.size();
        
        int count=0;
        
        for(int i = 1; i < n; i++) {
    if(seats[i] == 1 && seats[i-1] == 1)
        return false;
}
        
        if(seats[0]==0 && seats[1]==0){
            seats[0]=1;
            count++;
        }
        for(int i=1;i<n-1;i++){
            if(seats[i]==0 && seats[i-1]!=1 && seats[i+1]!=1){
                count++;
                seats[i]=1;
            }
        }
        
        if(seats[n-1]==0 && seats[n-2]==0){
            count++;
            seats[n-1]=0;
        }
        
        return count>=k;
    }
};