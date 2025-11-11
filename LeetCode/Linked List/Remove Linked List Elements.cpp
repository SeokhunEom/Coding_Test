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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;

        ListNode* curr = head;
        ListNode* next = head->next;

        while (curr->val == val) {
            head = next;
            curr = next;
            if (next) {
                next = next->next;
            } else {
                return nullptr;
            }
        }

        while (next != nullptr) {
            if (next->val == val) {
                curr->next = next->next;
                next = next->next;
            } else {
                curr = next;
                next = next->next;
            }
        }

        return head;
    }
};