/*https://leetcode.com/problems/sort-list/description/
 *time:61min
 *solution:
 *medium
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* end = head;
		ListNode* mid = head;
		ListNode* current = head;

		while (end != NULL && end->next != NULL) {
			end = end->next->next;
			current = mid;
			mid = mid->next;
		}

		current->next = NULL;
		ListNode* first = sortList(head);
		ListNode* second = sortList(mid);
		head = mergeList(first, second);
	
		return head;
	}

	ListNode* mergeList(ListNode* first, ListNode* second) {
		ListNode* dummy = new ListNode(0);
		ListNode* current = dummy;

		while (first != NULL && second != NULL) {
			if (first->val < second->val) {
				current->next = first;
				current = first;
				first = first->next;
			} else {
				current->next = second;
                                current = second;
                                second = second->next;
			}
		}

		if (first == NULL) {
			current->next = second;
		} else {
			current->next = first;
		}

		return dummy->next;
	}
};
