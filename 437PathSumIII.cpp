/*https://leetcode.com/problems/path-sum-iii/description/
 *time:21min
 *Solution:
 *easy
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		int count = 0;
		if (root == NULL)
			return count;

		path(root, sum, count);
		return count;
	}

private:
	void path(TreeNode* root, int sum, int& count) {
		if (root == NULL)
			return;

		help(root, sum, count);
		path(root->left, sum, count);
		path(root->right, sum, count);
	}

	void help(TreeNode* root, int sum, int& count) {
		if (root == NULL)
			return;

		if(root->val == sum) {
			count++;
		}

		help(root->left, sum - root->val, count);
		help(root->right, sum - root->val, count);
	}
};
