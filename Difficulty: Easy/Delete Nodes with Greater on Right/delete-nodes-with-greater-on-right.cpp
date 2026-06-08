/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    Node *compute(Node *head) {
        if (!head || !head->next) return head;

        head = reverse(head);

        int mx = head->data;
        Node* curr = head;

        while (curr && curr->next) {
            if (curr->next->data < mx) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else {
                curr = curr->next;
                mx = curr->data;
            }
        }

        return reverse(head);
    }
};