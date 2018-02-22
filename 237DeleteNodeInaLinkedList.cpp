/*https://leetcode.com/problems/delete-node-in-a-linked-list/description/
 *time:12min
 *solution:
 *easy
 */

class Solution {
public:
	void deleteNode(ListNode* node) {
		if (node == NULL || node->next == NULL) 
			return;

		node->val = node->next->val;
		node->next = node->next->next;
	}
};
