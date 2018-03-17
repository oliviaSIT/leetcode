/*https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *time:22min
 *solution: 2pointors
 *medium
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p0 = dummy;
        for (int i = 0; i < n; i++) 
            p0 = p0->next;
        
        ListNode* pre = dummy;
        ListNode* p = head;
        while(p0->next != NULL) {
            p0 = p0->next;
            p = p->next;
            pre = pre->next;
        }
        
        pre->next = p->next;
        
        return dummy->next;
    }
};
