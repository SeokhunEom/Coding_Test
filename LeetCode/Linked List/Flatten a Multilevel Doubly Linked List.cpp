/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }

        Node* curr = head;
        while(curr != nullptr) {
            if (curr->child != nullptr) {
                Node* child = curr->child;
                Node* next = curr->next;
                Node* tail = child;

                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;

                while(tail->next != nullptr) {
                    tail = tail->next;
                }

                tail->next = next;
                if (next != nullptr) {
                    next->prev = tail;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};