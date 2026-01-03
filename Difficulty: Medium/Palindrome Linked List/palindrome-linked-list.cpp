class Solution {
public:
    
    // Reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        // Step 1: find middle
        Node* slow = head;
        Node* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: reverse second half
        Node* secondHalf = reverse(slow->next);

        // Step 3: compare both halves
        Node* firstHalf = head;
        Node* temp = secondHalf;

        while (temp) {
            if (firstHalf->data != temp->data)
                return false;

            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        return true;
    }
};
