/*https://leetcode.com/problems/path-sum-ii/description/
 *time:40min
 *solution:DFS
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;

		vector<int> cur;
		help(res, cur, root, sum);
		return res;
	}

private:
	void help(vector<vector<int>>& res, vector<int>& cur, TreeNode* root, int sum) {
		if (root == NULL)
			return ;

		cur.push_back(root->val);	
		if (root->left == NULL && root->right == NULL && root->val == sum) 
				res.push_back(cur);
			
		help(res, cur, root->left, sum - root->val);
		help(res, cur, root->right, sum - root->val);
		
		cur.pop_back();
	}
};
