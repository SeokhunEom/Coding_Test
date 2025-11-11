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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listLength = 0;
        int removeIndex;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            listLength++;
            curr = curr->next;
        }
        removeIndex = listLength - n;

        if (removeIndex == 0) { // 첫 노드 삭제
            head = head->next;
            return head;
        }

        curr = head;
        for (int i = 0; i < removeIndex - 1; i++) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};