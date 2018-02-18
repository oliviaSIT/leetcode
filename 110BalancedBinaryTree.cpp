/*https://leetcode.com/problems/balanced-binary-tree/description/
 *solution:
 *time:
 *easy
 */

#include <iostream>
#include  <cstdlib>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 	};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;

		while (root->left != NULL || root->right != NULL) {
			if (abs(depth(root->left) - depth(root->right)) > 1)
				return false;
		}
		return true;        
	}

	int depth(TreeNode* root) {
		if (root == NULL)
                        return 0;

		return 1 + max(depth(root->left), depth(root->right));
	}


};
