/*https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description 
 *time:43min
 *easy
 */

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;

		level(root, res, 0);

		reverse(res.begin(), res.end());
		
		return res;
	}

	void level(TreeNode* root, vector<vector<int>>& res, int l) {
		if (root == nullptr)
			return;

		if (res.empty() || l > res.size() - 1) {
			vector<int> t;
			res.push_back(t);
		}

		res[l].push_back(root->val);

		level(root->left, res, l + 1);
		level(root->right, res, l + 1);
	}
};
