/* The functions which
builds the segment tree */
void build(int i,int l,int r,int arr[],int *seg){
    if(l==r){
        seg[i]=arr[l];
        return;
    }
    
    int mid = (l+r)/2;
    
    build(2*i+1,l,mid,arr,seg);
    build(2*i+2,mid+1,r,arr,seg);
    
    seg[i]=min(seg[2*i+1],seg[2*i+2]);
}

int *constructST(int arr[], int n) {
    // Your code here
    int *seg = new int[4*n];
    build(0,0,n-1,arr,seg);
    return seg;
}

/* The functions returns the
 min element in the range
 from a and b */

int query(int i,int l,int r, int arr[],int a,int b){
    if(l>b || r<a) return INT_MAX;
    
    if(l>=a && r<=b) return arr[i];
    
    int mid = (l+r)/2;
    
    return min(query(2*i+1,l,mid,arr,a,b),query(2*i+2,mid+1,r,arr,a,b));
}
 
int RMQ(int st[], int n, int a, int b) {
    return query(0,0,n-1,st,a,b);
}