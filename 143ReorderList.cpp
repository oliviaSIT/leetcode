/*https://leetcode.com/problems/reorder-list/description/
 *time:
 *solution: (1) 找到链表后一半 (2) 将后一半节点反转 (3) 将后一半节点依次插入前一半
 *medium
 */

class Solution {
public:
	void reorderList(ListNode* head) {
		ListNode* mid = findMid(head);
		ListNode* right = reverseList(mid);
		ListNode* left = head;

		while (right && right->next) {
			ListNode* target = right;
			right = right->next;
			target->next = left->next;
			left->next = target;
			left = left->next->next;
		}
	}

	ListNode* findMid(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}

	ListNode* reverseList(ListNode* head) {
		if (!head) 
			return head;
		ListNode *pre = head, *cur = head->next;
		while (cur) {
			ListNode* temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		head->next = NULL;
		return pre;
	}
};
