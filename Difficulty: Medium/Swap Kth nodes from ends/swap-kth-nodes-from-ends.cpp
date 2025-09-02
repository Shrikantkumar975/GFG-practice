class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        if (!head || k <= 0) return head;

        // Step 1: Count length
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Step 2: If k is invalid
        if (k > n) return head;

        // Step 3: If kth from start == kth from end (same node)
        if (2 * k - 1 == n) return head;

        // Step 4: Find kth node from start
        Node* fromS = head;
        for (int i = 1; i < k; i++) {
            fromS = fromS->next;
        }

        // Step 5: Find kth node from end = (n - k + 1)th from start
        Node* fromE = head;
        for (int i = 1; i < n - k + 1; i++) {
            fromE = fromE->next;
        }

        // Step 6: Swap their data
        swap(fromS->data, fromE->data);

        return head;
    }
};
