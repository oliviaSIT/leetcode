/*https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *time:31min 
 *solution: return to the father node
 *medium
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if (l && r)
            return root;
        else if (l)
            return l;
        else return r;
    }
};
