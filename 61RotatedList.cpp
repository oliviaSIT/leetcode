/*https://leetcode.com/problems/rotate-list/description/
 *time:17min
 *solution: 2 poitors
 *medium
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        
        int num = 0;
        ListNode* t = head;
        while (t != NULL) {
            t = t->next;
            num++;
        }
        
        k = k % num;
        
        if (k == 0)
            return head;
        
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* st = head;
        ListNode* ed = head;
        for (int i = 0; i < k - 1; i++)
            ed = ed->next;
        
        while (ed->next != NULL) {
            pre = pre->next;
            st = st->next;
            ed = ed->next;
        }
        
        ed->next = head;
        head = st;
        pre->next = NULL;
        
        return head;
    }
};
