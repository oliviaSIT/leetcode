/*
 *
 * think 5min, copy
 * [Solution]: Compare left subtree root is same as right subtree root, and recursive call.
*/

#include <iostream>

using namespace std;

class Solution {
public:
	bool isSymmetric(TreeNode* left, TreeNode *right) {
		if ((left == NULL) && (right == NULL)) {
        	     return true;
		}
        	if ((left != NULL) && (right != NULL)) {
            		return (left->val == right->val) && 
                        	isSymmetric(left->right, right->left) && 
                        	isSymmetric(left->left, right->right);
        	}
        	return false;
   	}
   	
	bool isSymmetric(TreeNode* root) {
        	if (root == NULL) {
           		return true;
        	}
        	return isSymmetric(root->left, root->right);
   	}

   
};

int main() {
	Solution sol;

	return 0;
}
