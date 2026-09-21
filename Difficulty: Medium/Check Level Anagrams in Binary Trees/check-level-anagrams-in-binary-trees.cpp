class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // Base cases: if both are null, they are anagrams; if only one is null, they aren't
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int size1 = q1.size();
            int size2 = q2.size();

            // If the number of nodes at this level doesn't match, they can't be anagrams
            if (size1 != size2) return false;

            vector<int> level1, level2;

            // Process current level for Tree 1
            for (int i = 0; i < size1; i++) {
                Node* curr = q1.front();
                q1.pop();
                level1.push_back(curr->data);

                if (curr->left) q1.push(curr->left);
                if (curr->right) q1.push(curr->right);
            }

            // Process current level for Tree 2
            for (int i = 0; i < size2; i++) {
                Node* curr = q2.front();
                q2.pop();
                level2.push_back(curr->data);

                if (curr->left) q2.push(curr->left);
                if (curr->right) q2.push(curr->right);
            }

            // Sort both levels to eliminate order differences
            sort(level1.begin(), level1.end());
            sort(level2.begin(), level2.end());

            // Direct vector comparison works perfectly once sorted!
            if (level1 != level2) return false;
        }

        // Ensure both queues are empty (in case one tree had extra levels)
        return q1.empty() && q2.empty();
    }
};
