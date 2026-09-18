/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
    
    
    void dfs(vector<int>&v,Node* root){
        if(!root) return;
        
        v.push_back(root->data);
        
        dfs(v,root->left);
        dfs(v,root->right);
    }
    
    int absDiff(Node *root) {
        // code here
        vector<int> v;
        
        int mini = INT_MAX;
        dfs(v,root);
        
        sort(v.begin(),v.end());
        
        for(int i=1;i<v.size();i++){
            mini = min(mini,v[i]-v[i-1]);
        }
        
        return mini;
    }
};