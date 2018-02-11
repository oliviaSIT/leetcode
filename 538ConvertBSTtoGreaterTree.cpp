/*https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 *time:56:33min
 *solution: recurse
 */

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void changeKey(TreeNode* root, int& cur_sum) {
		if (!root) return;

		if (root->right) changeKey(root->right, cur_sum);
		
		cur_sum += root->val;
		root->val = cur_sum;

		if (root->left) changeKey(root->left, cur_sum);
	}

        TreeNode* convertBST(TreeNode* root) {
        	int cur_sum = 0;
		changeKey(root, cur_sum);
		return root;
        }
};

