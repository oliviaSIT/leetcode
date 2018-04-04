/*https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *time: 34min
 *solution:DFS
 *medium
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
        else root->right->next = NULL;
        
        connect(root->right);
        connect(root->left);
    }
};
