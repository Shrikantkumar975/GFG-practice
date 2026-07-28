class Solution {
  public:
    int N;
    vector<int> segTree;
    
    void build(int arr[],int i, int l, int r){
        if(l==r){
            segTree[i]=arr[l];
            return;
        }
        
        int mid = (l+r)/2;
        
        build(arr,2*i+1,l,mid);
        build(arr,2*i+2,mid+1,r);
        
        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
    }
    
    
    int query(int i, int l,int r, int left, int right){
        if(l>right || r<left){
            return 0;
        }
        if(l>=left && r<=right){
            return segTree[i];
        }
        
        int mid = (l+r)/2;
        
        return query(2*i+1,l,mid,left,right) + query(2*i+2,mid+1,r,left,right);
    }
    
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        N=n;
        segTree.resize(4*n);
        
        build(arr,0,0,N-1);
        vector<int> res;    
        
        for(int i=0;i<2*q;i+=2){
            res.push_back(query(0,0,N-1,queries[i]-1,queries[i+1]-1));
        }
        
        return res;
        
    }
};