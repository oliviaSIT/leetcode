/*https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *time:10min
 *solution
 *easy
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur != NULL) {
            if (pre->val == cur->val) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            
            cur = cur->next;
        }
        
        return head;
    }
};
