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
    ListNode* middleNode(ListNode* head) {
        int nodeLen = 0;
        ListNode* nodeHalf = head;
        ListNode* nodeEnd = head;
        while (nodeEnd) {
            nodeLen++;
            if (nodeLen % 2 == 0) {
                nodeHalf = nodeHalf->next;
            }
            nodeEnd = nodeEnd->next;
        }
        return nodeHalf;
    }
};