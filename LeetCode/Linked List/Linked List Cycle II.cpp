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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fastNode = head;
        ListNode *slowNode = head;
        bool isCycle = false;

        while (fastNode != nullptr && fastNode->next != nullptr) {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
            if (fastNode == slowNode) {
                isCycle = true;
                break;
            }
        }

        if (isCycle) {
            fastNode = head;
            while (fastNode != slowNode) {
                fastNode = fastNode->next;
                slowNode = slowNode->next;
            }
            return fastNode;
        } else {
            return nullptr;
        }
    }
};