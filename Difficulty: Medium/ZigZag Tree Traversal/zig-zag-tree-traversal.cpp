/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue<Node*> q;
        q.push(root);
        
        vector<int> ans;
        bool even = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            while(size){
                Node* a = q.front();
                q.pop();
                v.push_back(a->data);
                if(a->left) q.push(a->left); 
                if(a->right) q.push(a->right); 
                size--;
            }
            if(even){
                even = false;
            }else{
                reverse(v.begin(),v.end());
                even =true;
            }
            for(int i=0;i<v.size();i++){
                    ans.push_back(v[i]);
            }
        }
        return ans;
    }
};