class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        if (!head || !head->next || k == 0) {
            return head;
        }

        Node* temp = head;
        int l = 1; // Fix: start from 1, as head is already 1 node
        while (temp->next) {
            l++;
            temp = temp->next;
        }

        k %= l;
        if (k == 0) return head;

        // Move to (k-1)th node
        Node* slow = head;
        for (int i = 1; i < k; i++) {
            slow = slow->next;
        }

        // new head is slow->next
        Node* newHead = slow->next;
        slow->next = nullptr;
        temp->next = head;

        return newHead;
    }
};
