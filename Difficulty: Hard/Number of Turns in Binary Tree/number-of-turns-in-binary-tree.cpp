class Solution {
  public:

    Node* findLCA(Node* root, int p, int q) {
        if (root == nullptr)
            return nullptr;

        if (root->data == p || root->data == q)
            return root;

        Node* left = findLCA(root->left, p, q);
        Node* right = findLCA(root->right, p, q);

        if (left && right)
            return root;

        return left ? left : right;
    }

    bool findPath(Node* root, int target, vector<int>& path) {
        if (root == nullptr)
            return false;

        if (root->data == target)
            return true;

        // Left = 0
        path.push_back(0);

        if (findPath(root->left, target, path))
            return true;

        path.pop_back();

        // Right = 1
        path.push_back(1);

        if (findPath(root->right, target, path))
            return true;

        path.pop_back();

        return false;
    }

    int countTurns(vector<int>& path) {
        int turns = 0;

        for (int i = 1; i < path.size(); i++) {
            if (path[i] != path[i - 1])
                turns++;
        }

        return turns;
    }

    int numberOfTurns(Node* root, int p, int q) {

        Node* lca = findLCA(root, p, q);

        if (lca == nullptr)
            return -1;

        vector<int> pathP, pathQ;

        findPath(lca, p, pathP);
        findPath(lca, q, pathQ);

        int turns = 0;

        // If p is not LCA, count turns on p -> LCA path
        // Reversing does not change the number of turns.
        turns += countTurns(pathP);

        // If q is not LCA, count turns on LCA -> q path
        turns += countTurns(pathQ);

        // If both paths exist, the direction at LCA
        // changes from pathP's first direction to pathQ's first direction.
        if (!pathP.empty() && !pathQ.empty()) {
            if (pathP[0] != pathQ[0])
                turns++;
        }

        return turns == 0 ? -1 : turns;
    }
};