/*https://leetcode.com/problems/sum-of-left-leaves/description
 *time:49min
 *solution:
 *easy
 */

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root)
			return 0;

		return sumofLeftLeaves(root, false);		
	}

	int sumofLeftLeaves(TreeNode* root, bool isLeft) {
		if (!root)
			return 0;

		if (!root->left && !root->right) {
			if (isLeft)
				return root->val;
			else return 0;
		}

		return sumofLeftLeaves(root->left, true) + sumofLeftLeaves(root->right, false);
	}
};
