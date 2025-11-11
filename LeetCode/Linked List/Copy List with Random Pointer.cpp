/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* temp = head;
        while (temp) {
            Node* new_node = new Node(temp->val);
            new_node->next = temp->next;
            temp->next = new_node;
            temp = new_node->next;
        }

        temp = head;
        while (temp) {
            Node* new_node = temp->next;
            if (temp->random) {
                new_node->random = temp->random->next;
            } else {
                new_node->random = nullptr;
            }
            temp = new_node->next;
        }

        Node* copy_head = head->next;
        temp = head;
        while (temp) {
            Node* new_node = temp->next;
            temp->next = new_node->next; 
            if (new_node->next) {
                new_node->next = new_node->next->next;
            }
            temp = temp->next;
        }

        return copy_head;
    }
};