/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int distCandy(Node* root) {

    if (root == nullptr) return 0;
    int ans = 0;

    stack<pair<Node*, int>> stk;

    unordered_map<Node*, int> balance;

    // Push root node into the stack 
    // with state 0 (not processed)
    stk.push({root, 0});

    while (!stk.empty()) {

        // Get the top node and its state 
        // from the stack
        auto curr = stk.top();
        auto node = curr.first;
        auto state = curr.second;
        stk.pop();

        if (node == nullptr) continue;

        // If state is 0, push node back with 
        // state 1 (post-processing)
        if (state == 0) {

            // Push current node back with 
            // state 1 for post-order processing
            stk.push({node, 1});

            stk.push({node->left, 0});

            stk.push({node->right, 0});

        } 
        else {

            int leftBalance = balance[node->left];

            int rightBalance = balance[node->right];

            // Add moves required for left and right subtrees
            ans += abs(leftBalance) + abs(rightBalance);

            // Calculate current node's balance: (candies - 1)
            balance[node] 
              = node->data + leftBalance + rightBalance - 1;
        }
    }
  
    return ans;
}
};