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
    vector<int> topView(Node *root) {
        // code here
        vector<int> v;
        
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        
        q.push({root,0});
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                pair<Node*, int> curr = q.front();
                q.pop();
                
                if(mpp.find(curr.second)==mpp.end()) mpp[curr.second]=curr.first->data;
                
                if(curr.first->left) q.push({curr.first->left,curr.second-1});
                if(curr.first->right) q.push({curr.first->right,curr.second+1});
            }
        }
        
        for(auto m: mpp){
            v.push_back(m.second);
        }
        
        return v;
    }
};