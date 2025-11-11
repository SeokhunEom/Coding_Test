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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int index = 3;
        ListNode* odd_head = head;
        ListNode* odd_tail = odd_head;
        ListNode* even_head = head->next;
        ListNode* even_tail = even_head;
        ListNode* curr = head->next->next;

        while (curr != nullptr) {
            if (index % 2 == 0) { // even
                even_tail->next = curr;
                even_tail = even_tail->next;
            } else { // odd
                odd_tail->next = curr;
                odd_tail = odd_tail->next;
            }
            curr = curr->next;
            index++;
        }

        odd_tail->next = even_head;
        even_tail->next = nullptr;
        return odd_head;
    }
};
