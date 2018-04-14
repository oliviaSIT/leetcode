/*https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *time:19min
 *solution:dfs
 *medium
 */

class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root) return;
        vector<TreeNode*> allNodes;
        preorder(root, allNodes);
        int n = allNodes.size();
        for(int i=0; i<n-1; i++) {
            allNodes[i]->left = NULL;
            allNodes[i]->right = allNodes[i+1];
        }
        allNodes[n-1]->left = allNodes[n-1]->right = NULL;
    }
    
    void preorder(TreeNode *root, vector<TreeNode*> &allNodes) {
        if(!root) return;
        allNodes.push_back(root);
        preorder(root->left, allNodes);
        preorder(root->right, allNodes);
    }
};
