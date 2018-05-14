/*https://leetcode.com/problems/house-robber-iii/description/
 *time:33min
 *solution:dfs res[0] not rob, res[1] rob
 *medium
 */

class Solution {
public:
	int rob(TreeNode* root) {
		vector<int> res = help(root);
		return max(res[0], res[1]);
	}

private:
	vector<int> help(TreeNode* root) {
		vector<int> res(2, 0);
		if (!root)
			return res;

		vector<int> l = help(root->left);
		vector<int> r = help(root->right);
		res[0] = max(l[0], l[1]) + max(r[0], r[1]);
		res[1] = l[0] + r[0] + root->val;
		return res;
	}
};
