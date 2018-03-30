/*https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *time:49min
 *solution:queue
 *medium
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        
        preorder(root, res);
        return res;
    }
    
private:
    void preorder(TreeNode* root, vector<int>& res) {
        if (root == NULL)
            return;
        
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
};
*/

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;

		stack<TreeNode*> s;
		s.push(root);

		TreeNode* cur = root;

		while (!s.empty()) {
			cur = s.top();
			s.pop();
			res.push_back(cur->val);
			if (cur->right != NULL)
				s.push(cur->right);

			if (cur->left != NULL)
                                s.push(cur->left);
		}

		return res;
	}
};
