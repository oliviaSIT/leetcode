/*https://leetcode.com/problems/insertion-sort-list/description/
 *time:
 *solution:
 *medium
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* current = head->next;
		ListNode* prev = head;
		
		while (current != NULL) {
			ListNode* run = new ListNode(0);
			run->next = head;
			bool get = false;
			
			while (run->next != current) {
				if (run->next->val > current->val) {
					if (run->next == head)
						head = current;
					
					prev->next = current->next; //seprate current
					// insert current
					current->next = run->next;
					run->next = current;
					current = prev->next;
					get = true;
					break;
				}
				
				run = run->next;
			}

			if (!get) {
				current = current->next;
				prev = prev->next;
			}
		}

		return head;
	}
};
