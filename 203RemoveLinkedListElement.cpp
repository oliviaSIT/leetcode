/*https://leetcode.com/problems/remove-linked-list-elements/description/
 *time: 14min
 *solution
 *easy
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        
        while (head != NULL) {
            if (head->val == val) {
                    pre->next = head->next;
            } else {
                pre = head;
            }
            
            head = head->next;
        }
        
       
        return dummy->next;
    }
};
