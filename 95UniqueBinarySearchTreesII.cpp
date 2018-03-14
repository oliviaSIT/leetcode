/*https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *time:63min
 *solution: 
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;

		if (n == 0)
			return res;

		res = generate(1, n);
		return res;
	}

	vector<TreeNode*> generate(int start, int end) {
		vector<TreeNode*> res;
		if (start > end) {
			res.push_back(nullptr);
			return res;
		}

		for (int i = start; i <= end; i++) {
			vector<TreeNode*> lefts = generate(start, i - 1);
			vector<TreeNode*> rights = generate(i + 1, end);

			for (int j = 0; j < (int)lefts.size(); j++) {
				for (int k = 0; k < (int)rights.size(); k++) {
					TreeNode* root = new TreeNode(i);
					root->left = lefts[j];
					root->right = rights[k];
					res.push_back(root);					
				}
			}
		}

		return res;
	}
};
