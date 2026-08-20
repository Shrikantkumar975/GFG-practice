class Solution {
  public:
    int diff;

    void check(Node* root, int maxi) {
        if (root == nullptr)
            return;

        // root is a descendant of some previous ancestor
        diff = max(diff, maxi - root->data);

        // root can now become the maximum ancestor
        maxi = max(maxi, root->data);

        check(root->left, maxi);
        check(root->right, maxi);
    }

    int maxDiff(Node* root) {
        diff = INT_MIN;

        // Don't compare root with itself
        if (root->left)
            check(root->left, root->data);

        if (root->right)
            check(root->right, root->data);

        return diff;
    }
};
