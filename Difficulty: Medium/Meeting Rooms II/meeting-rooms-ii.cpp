class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int count =0;
        int maxcount=0;
        int i=0;
        int j=0;
        
        while(j<start.size()){
            if(start[j]<end[i]){
                count++;
                j++;
            }else{
                count--;
                i++;
            }
            
            maxcount = max(count,maxcount);
            
        }
        
        return maxcount;
        
    }
};
