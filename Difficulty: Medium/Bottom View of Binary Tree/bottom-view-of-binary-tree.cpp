/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node* root) {
    if (!root) return {};

    // Map to store the last node's data
    // at each horizontal distance
    unordered_map<int, int> hash;
    int minHD = 0, maxHD = 0;

    // Queue for level order traversal
    // storing <node, horizontal distance>
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        Node* node = front.first;
        int hd = front.second;

        // Update the horizontal distance -> node data
        hash[hd] = node->data;

        minHD = min(minHD, hd);
        maxHD = max(maxHD, hd);

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    vector<int> ans;
    for (int i = minHD; i <= maxHD; i++)
        ans.push_back(hash[i]);

    return ans;
}
};