/*https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *time: 5min
 *solution: recurse
 *easy
 */

class Solution {
public:
	int maxDepth(TreeNode* root) {
		int res = depth(root);
		return res;
 	}
    
	int depth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		else {
			return 1 + max(depth(root->left), depth(root->right));
		}
	}
};
