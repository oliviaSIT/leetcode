/*https://leetcode.com/problems/reverse-linked-list-ii/description/
 *time:56min
 *solution:
 *medium
 */

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m<1 || m>=n || !head) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        
        // move head to (m-1)th node
        for(int i=0; i<m-1; i++)
            head = head->next;
        
        // reverse list from pre with length n-m+1    
        ListNode *pre = head->next, *cur = pre->next;
        for(int i=0; i<n-m; i++) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        
        head->next->next = cur;
        head->next = pre;
        head = dummy->next;
        delete dummy;
        return head;
    }
};
