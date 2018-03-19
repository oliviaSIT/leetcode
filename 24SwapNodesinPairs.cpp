/*https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *time:18min
 *solution
 *medium
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* st = head;
        ListNode* ed = head->next;
        ListNode* pre = dummy;
        
        while (ed != NULL) {
            ListNode* t = ed->next;
            ed->next = st;
            st->next = t;
            pre->next = ed;
        
            pre = st;
            st = pre->next;
            if (st == NULL)
                break;
            ed = st->next;
        }
        
        return dummy->next;
    }
};
