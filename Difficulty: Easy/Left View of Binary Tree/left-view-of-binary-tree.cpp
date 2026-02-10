/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
      void dfs(Node* root,vector<int> &v,int &level,int curr){
        if(curr==level){
            v.push_back(root->data);
            level++;
        }

        if(root->left) dfs(root->left,v,level,curr+1);
        if(root->right) dfs(root->right,v,level,curr+1);
    }

    vector<int> leftView(Node *root) {
         if(!root) return {};
        vector<int> v;
        int level =1;

        dfs(root,v,level,1);

        return v;
        
    }
};