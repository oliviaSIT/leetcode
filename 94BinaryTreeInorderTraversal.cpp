/*https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *time:
 *solution: stack
 *medium
 */

/*
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		inorderTrav(root, res);
		return res;
	}
    
	void inorderTrav(TreeNode *root, vector<int>& res) {
		if(!root) 
			return;
		inorderTrav(root->left, res);
		res.push_back(root->val);
		inorderTrav(root->right, res);
	}
};
*/
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
        vector<int> inorderTraversal(TreeNode *root) {
                vector<int> res;
		TreeNode* current = root;
		stack<TreeNode*> s;

		while (current || !s.empty()) {
			if (current) {
				s.push(current);
				current = current->left;	
			} else {
				current = s.top();
				s.pop();
				res.push_back(current->val);
				current = current->right;
			}
		}

		return res;

	}
};

