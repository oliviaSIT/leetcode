/*https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *time:32min
 *solution:pre-order
 *medium
 */

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int res = 0;
		sum(root, 0, res);
		return res;
	}

	void sum(TreeNode* root, int cur, int& res) {
		if (!root)
			return;

		cur = cur * 10 + root->val;
		if (!root->left && !root->right)
			res += cur;

		if (root->left)
			sum(root->left, cur, res);

		if (root->right)
			sum(root->right, cur, res);
	}
};
