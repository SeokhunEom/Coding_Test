/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA = headA;
        ListNode *currB = headB; 

        while (currA != nullptr) {
            currA->val = currA->val * -1;
            currA = currA->next;
        }
        
        while (currB != nullptr) {
            if (currB->val < 0) {
                break;
            }
            currB = currB->next;
        }

        currA = headA;
        while (currA != nullptr) {
            if (currA->val > 0) {
                break;
            }
            currA->val = currA->val * -1;
            currA = currA->next;
        }

        return currB;
    }
};