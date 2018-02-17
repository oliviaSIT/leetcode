/*https://leetcode.com/problems/add-two-numbers/description/
 *time:2h
 *solution:
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode*, l2) {
		if (l1 == NULL) {
			return l2; 
		}

		if (l2 == NULL) {
			return l1; 
		}

		ListNode* dummy = new ListNode(0); 
		ListNode* pre = dummy; 
		int c = 0; 
		int v; 
		while (l1 != NULL && l2 != NULL) {
			v = l1->val + l2->val + c; 
			l1 = l1->next; 
			l2 = l2->next;
 
			if (v >= 10) {
				c = v / 10; 
				v = v % 10; 
			} else {
				c = 0; 
			}

			ListNode* cur = new ListNode(v); 
			pre->next = cur; 	
			pre = cur; 
		}
		
		if (l2 != NULL) {
			l1 = l2; 
		}

		while (l1 != NULL) {
			v = l1->val + c; 
			l1 = l1->next; 
			if (v >= 10) {
				c = v / 10; 
				v = v % 10; 
			} else {
				c = 0; 
			}

			ListNode* cur = new ListNode(v); 
			pre->next = cur; 
			pre = cur; 
		
		}

		if (c != 0) {
			ListNode* cur = new ListNode(c); 
			pre->next = cur; 
		}
		
		return dummy->next;
	}

};
