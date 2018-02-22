/*https://leetcode.com/problems/count-complete-tree-nodes/description/
 *time:
 *solution:
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
                if (root == NULL)
                        return 0;

                int l_Height = leftHeight(root->left);
                int r_Height = rightHeight(root->right);
                int height;
                if (l_Height == r_Height) {
                        height = l_Height + 1;
                        return (1 << height) - 1;
                }

                return countNodes(root->left) + countNodes(root->right) + 1;
    }

        int leftHeight(TreeNode* node) {
                int h = 0;
                while (node != NULL) {
                        h++;
                        node = node->left;
                }

                return h;
        }

        int rightHeight(TreeNode* node) {
                int h = 0;
                while (node != NULL) {
                        h++;
                        node = node->right;
                }

                return h;

        }
};
