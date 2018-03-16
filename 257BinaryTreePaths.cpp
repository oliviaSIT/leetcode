/*https://leetcode.com/problems/binary-tree-paths/description/
 *time:
 *solution:
 *easy
 */

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;

		if (!root) 
			return res;

		getPath(root, res, to_string(root->val));

		return res;

	}

	void getPath(TreeNode* root, vector<string>& res, string& str) {
		if (!root->left && !root->right) {
			res.push_back(str);
			return;
		}

		
		if (!root->left)
			getPath(root->left, res, to_string(root->left->val));

		if (!root->right)
                        getPath(root->right, res, to_string(root->right->val));

	}
};
