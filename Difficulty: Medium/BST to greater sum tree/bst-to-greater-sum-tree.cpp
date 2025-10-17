/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    

// Calculate height
int getHeight(Node* root, int h) {
    if (root == nullptr) return h - 1;
    return max(getHeight(root->left, h + 1), getHeight(root->right, h + 1));
}
// Print Level order
void levelOrder(Node* root) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    int lastLevel = 0;

    // function to get the height of tree
    int height = getHeight(root, 0);

    // printing the level order of tree
    while (!q.empty()) {
        auto [node, lvl] = q.front();
        q.pop();

        if (lvl > lastLevel) {
            cout << "\n";
            lastLevel = lvl;
        }

        // all levels are printed
        if (lvl > height) break;

        // printing null node
        if (node->data != -1) cout << node->data << " ";
        else cout << "N ";

        // null node has no children
        if (node->data == -1) continue;

        if (node->left == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->left, lvl + 1});

        if (node->right == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->right, lvl + 1});
    }
}

// Function to update the tree 
void updateTree(Node* root, int& sum) {
    if (root == nullptr) {
        return;
    }

    // Traverse the right subtree first (larger values)
    updateTree(root->right, sum);

    // Update the sum and the current node's value
    sum += root->data;
    root->data = sum - root->data;

    // Traverse the left subtree (smaller values)
    updateTree(root->left, sum);
}

// Return the updated tree
void transformTree(Node* root) {
  
  	// Initialize the cumulative sum
    int sum = 0; 
    updateTree(root, sum);
}

};