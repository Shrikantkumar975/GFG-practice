class Solution {
  public:

    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;

        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL;
        return result;
    }

    Node *flatten(Node *root) {
        // base case
        if (!root || !root->next)
            return root;

        // flatten the rest
        root->next = flatten(root->next);

        // merge current with flattened list
        root = merge(root, root->next);

        return root;
    }
};
