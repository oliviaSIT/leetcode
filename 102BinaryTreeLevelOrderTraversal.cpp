/*https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *time:32min
 *solution:queue
 *medium
 */

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;
		
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int size = q.size();
			vector<int> level;

			for (int i = 0; i < size; i++) {
				TreeNode* head = q.front();
				q.pop();
				level.push_back(head->val);

				if (head->left != NULL)
					q.push(head->left);

				if (head->right != NULL)
					q.push(head->right);

			}

			res.push_back(level);

		}
		
		return res;
	}
};
