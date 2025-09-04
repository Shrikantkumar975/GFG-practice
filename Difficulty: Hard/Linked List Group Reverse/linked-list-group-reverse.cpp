class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (head == nullptr) return nullptr;

        Node* current = head;
        Node* next = nullptr;
        Node* prev = nullptr;

        int count = 0;

        // Count total nodes available from head
        Node* temp = head;
        int total = 0;
        while (temp != nullptr) {
            total++;
            temp = temp->next;
        }

        // If remaining nodes are < k, reverse them as well
        if (total < k) k = total;

        // Reverse k nodes
        count = 0;
        current = head;
        while (count < k && current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        // Recursive call for the rest of the list
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};
