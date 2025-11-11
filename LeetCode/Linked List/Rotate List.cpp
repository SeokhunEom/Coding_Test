/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }

        int len = 0;
        ListNode* curr=head;
        ListNode* tail=NULL;

        while(curr != NULL){
            len++;
            tail = curr;
            curr = curr->next;
        }
        if(k == len) {
            return head;
        }
        k = k % len;

        curr = head;
        for (int i = 0, l = len - k - 1; i < l; i++) {
            curr = curr->next;
        }
        tail->next = head;

        ListNode* new_head = curr->next;
        curr->next = NULL;
        return new_head;
    }
};