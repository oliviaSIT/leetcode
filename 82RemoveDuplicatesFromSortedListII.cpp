/*https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *time: 22min
 *solution:
 *medium
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* last = dummy;
        ListNode* cur = head;
        ListNode* n = head->next;
        while (n) {
            if (n->val != cur->val) {
                last = cur;
                cur = n;
            } else {
                while (n && n->val == cur->val)
                    n = n->next;
                
                cur = n;
                last->next= cur;
            }
            
            if (n)
                n = n->next;
            
        }
    
        return dummy->next;
    }
};
