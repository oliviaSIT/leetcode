/*https://leetcode.com/problems/add-two-numbers-ii/description/
 *time:
 *solution:
 *medium
 */

#include <iostream>

using namespace std;

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        	ListNode *r1 = l1, *r2 = l2;
	while (r1 != NULL && r2 != NULL) {
            		r1 = r1->next;
            		r2 = r2->next;
        	}

	ListNode *h1 = l1, *h2 = l2;
	while (r1 != NULL) {
		h1 = h1->next;
		r1 = r1->next;
	}


	while (r2 != NULL) {
		h2 = h2->next;
		r2 = r2->next;
	}

	ListNode *cur = NULL;
	while (l1 != h1) {
		ListNode *tmp = new ListNode(l1->val);
		tmp->next = cur;
		cur = tmp;
		l1 = l1->next;
	}

	while (l2 != h2) {
		ListNode *tmp = new ListNode(l2->val);
		tmp->next = cur;
		cur = tmp;
		l2 = l2->next;
        }

	while (h1 != NULL) {
		ListNode *tmp = new ListNode(h1->val + h2->val);
		tmp->next = cur;
		cur = tmp;
		h1 = h1->next;
		h2 = h2->next;
	}

	ListNode *head = cur, *pre = cur;
	int carry = 0;
	while (cur != NULL) {
		cur->val += carry;
		if (cur->val > 9) {
			carry = cur->val / 10;
			cur->val = cur->val % 10;
		} else {
			carry = 0;
		}

		pre = cur;
		cur = cur->next;
	}

	if (carry > 0)
		pre->next = new ListNode(carry);

		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		while (head->next != NULL) {
			ListNode *curr = head->next;
			ListNode *tmp = curr->next;
			curr->next = dummy->next;
			dummy->next = curr;
			head->next = tmp;
		}

	ListNode *res = dummy->next;
	delete dummy;//why?
	return res;
	}
};
