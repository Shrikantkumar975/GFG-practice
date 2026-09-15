/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        vector<int> ans;
        
        queue<Node*>q;
        q.push(root);
        
        int curr=1;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                Node* u = q.front();
                q.pop();
                
                if(!u->left && !u->right){
                    ans.push_back(curr);
                    continue;
                }
                
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            curr++;
        }
        
        sort(ans.begin(),ans.end());
        
        int count=0;
        int a=0;
        int i=0;
        while(i<ans.size() && a+ans[i]<=k){
            a+=ans[i];
            count++;
            i++;
        }
        
        return count;
        
    }
};