/*https://leetcode.com/problems/linked-list-cycle/description/
 *solution: 2 pointors slow & fast
 *time:
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
	bool hasCycle(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;

		do {
			if (fast == NULL || fast-> == NULL) {
				return false;
			}

			fast = fast->next->next;
			slow = slow->next;
		} while (slow != fast);

		return true;
	
	}
}
