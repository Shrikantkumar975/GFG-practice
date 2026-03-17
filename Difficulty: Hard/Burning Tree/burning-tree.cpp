/*
class Node {
  public:
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
    int minTime(Node* root, int target) {
        unordered_map<int,vector<int>> mpp;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* curr = q.front();
            int currVal = curr->data;
            q.pop();
            
            if(curr->left){
                mpp[currVal].push_back(curr->left->data);
                mpp[curr->left->data].push_back(currVal);
                q.push(curr->left);
            }
            if(curr->right){
                mpp[currVal].push_back(curr->right->data);
                mpp[curr->right->data].push_back(currVal);
                q.push(curr->right);
            }
        }
        
        unordered_set<int> st;
        
        queue<int> q1;
        q1.push(target);
        st.insert(target);
        int ans = -1;
        
        while(!q1.empty()){
            ans++;
            int size = q1.size();
            while(size--){
                int curr = q1.front();
                q1.pop();
                
                for(int a: mpp[curr]){
                    if(st.find(a)==st.end()){
                        q1.push(a);
                        st.insert(a);
                    }
                }
            }
        }
        
        return ans;
    }
};