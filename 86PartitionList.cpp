/*https://leetcode.com/problems/partition-list/description/
 *time:30min
 *solution:2 points
 *corner case:the end of the larger one should be NULL
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode* dummy01 = dummy1;
        ListNode* dummy02 = dummy2;
        ListNode* cur = head;
        while (cur != NULL) {
            if (cur->val < x) {
                dummy1->next = cur;
                dummy1 = dummy1->next;
            } else {
                dummy2->next = cur;
                dummy2 = dummy2->next;
            }
            
            cur = cur->next;
        }
        dummy2->next = NULL;
        dummy1->next = dummy02->next;
        return dummy01->next;
    }
};
