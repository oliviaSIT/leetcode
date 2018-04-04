/*https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *time:45min 
 *solution: set dummy use recursive BFS
 *medium
 */

class Solution {
public:
	void connect(TreeLinkNode* root) {
		if (!root) 
			return;

		TreeLinkNode* dummy = new TreeLinkNode(0);

		for (TreeLinkNode* cur = root, *pre = dummy; cur; cur = cur->next) {
			if (cur->left) {
				pre->next = cur->left;
				pre = pre->next;
			}

			if (cur->right) {
				pre->next = cur->right;
				pre = pre->next;
			}
		}

		connect(dummy->next);
	}
};
