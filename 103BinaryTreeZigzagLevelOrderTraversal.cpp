/*https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *time:20min
 *solution:bfs, queue
 *medium
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (root == NULL)
            return res;
        
        queue<TreeNode*> q;
        int height = 0;
        
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> cur;
            
            for (int i = 0; i < size; i++) {
                TreeNode* p = q.front();
                q.pop();
                cur.push_back(p->val);
                
                if (p->left) 
                    q.push(p->left);
                
                if (p->right)
                    q.push(p->right);
            }
            
            if (height % 2 != 0)
                reverse(cur.begin(), cur.end());
            
            height++;
            res.push_back(cur);
        }
        
        return res;
    }
};
