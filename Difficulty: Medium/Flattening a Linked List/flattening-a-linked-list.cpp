class Solution {
  public:
    Node* merge(Node* list1, Node* list2) {
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        
        while (list1 && list2) {
            if (list1->data < list2->data) {
                res->bottom = list1;
                list1 = list1->bottom;
            } else {
                res->bottom = list2;
                list2 = list2->bottom;
            }
            res = res->bottom;
        }
        
        if (list1) res->bottom = list1;
        else res->bottom = list2;
        
        return dummyNode->bottom;
    }

    Node* flatten(Node* head) {
        if (!head || !head->next) return head;  // ✅ fixed null check
        
        head->next = flatten(head->next);  // flatten rest of list
        head = merge(head, head->next);    // merge current list with flattened next
        
        return head;
    }
};
