/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    map<int,int> mpp;
    
    void dfs(Node* root,int curr){
        if(!root) return;
        
        mpp[curr]+=root->data;
        
        if(root->left){
            dfs(root->left,curr-1);
        }
        
        if(root->right){
            dfs(root->right,curr+1);
        }
    }
    vector<int> verticalSum(Node* root) {
        dfs(root,0);
        
        vector<int> ans;
        
        for(auto m:mpp){
            ans.push_back(m.second);
        }
        
        return ans;
        
    }
};