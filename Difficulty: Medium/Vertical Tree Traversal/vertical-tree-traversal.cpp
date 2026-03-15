/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        map < int, vector<pair<int, int>>> mp;

        queue<pair<Node*, int>> q;

        int step = -1;
        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();
            step++;
            while (size--) {
                auto [a, b] = q.front();
                q.pop();
                mp[b].push_back({step, a->data});
                if (a->left != NULL)
                    q.push({a->left, b - 1});
                if (a->right != NULL)
                    q.push({a->right, b + 1});
            }
        }
        
        for (auto x : mp) {
            // sort(x.second.begin(), x.second.end());

            vector<int> v;
            for(auto [a,b]: x.second){
                v.push_back(b);
            }
            ans.push_back(v);
        }
        return ans;
    }
};