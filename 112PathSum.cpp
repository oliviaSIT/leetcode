/*https://leetcode.com/problems/path-sum/description/
 *time:21min
 *solution:
 *easy
 */

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
	if(root == NULL)
		return false;
	
	return DFS(sum, 0, root);
 	}

	bool DFS(int sum, int cur, TreeNode* root) {
		if(root == NULL)
			return false;

		cur += root->val;
		if(root->left == NULL && root->right == NULL) {
			if(sum == target)
				return true;
			else return false;
		}

		bool leftPart = DFS(sum, cur, root->left);
		bool rightPart = DFS(sum, cur, root->right);
		return leftPart || rightPart;
	}
};
