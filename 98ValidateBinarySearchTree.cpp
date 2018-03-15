/*https://leetcode.com/problems/validate-binary-search-tree/description/
 *time:43min
 *solution:
 *medium
 */
/*
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (root == nullptr)
			return true;

		if (root->left == nullptr && root->right == nullptr)
			return true;
		
		if (root->left == nullptr && root->right != nullptr)
			return (root->val < Min(root->right)) && (isValidBST(root->right));
		
		if (root->left != nullptr && root->right == nullptr)
                        return (root->val > Max(root->left)) && (isValidBST(root->left));

		return (root->val < Min(right->val)) && (root->val > Max(root->left) && (isValidBST(root->right)) && (isValidBST(root->left));
	}

		int Max(TreeNode* root) {
			
		}
};
*/

class Solution {
public:
        bool isValidBST(TreeNode* root) {
		return isBST(root, NULL, NULL);
	}

	bool isBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
		if (root == NULL)
			return true;

		if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
			return false;

		return isBST(root->left, minNode, root) && isBST(root->right, root, maxNode);
	}
};
