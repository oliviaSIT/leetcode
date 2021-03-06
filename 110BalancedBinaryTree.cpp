/*https://leetcode.com/problems/balanced-binary-tree/description/
 *solution:36min
 *time:
 *easy
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>

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

		return isBalanced(root->left) && isBalanced(root-> right) && abs(depth(root->left) - depth(root->right)) <= 1;
			        
	}

	int depth(TreeNode* root) {
		if (root == NULL)
                        return 0;

		return 1 + max(depth(root->left), depth(root->right));
	}


};
