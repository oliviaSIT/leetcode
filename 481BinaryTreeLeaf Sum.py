"""
http://www.lintcode.com/en/problem/binary-tree-leaf-sum/
time: 20min
Definition of TreeNode:

"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    """
    @param: root: the root of the binary tree
    @return: An integer
    """
    def leafSum(self, root):
        # write your code here
        leaf = []
        self.dfs(root,leaf)

        return sum(leaf)

    def dfs(self, root, leaf):
        if root is None:
            return

        if root.left is None and root.right is None:
            leaf.append(root.val)


        self.dfs(root.left, leaf)
        self.dfs(root.right, leaf)

node1, node2, node3, node4, node5 = TreeNode(1), TreeNode(2), TreeNode(4), TreeNode(2), TreeNode(3)
node1.left = node2
node1.right = node3
node2.left = node4
node2.right = node5

ans = Solution()
print(ans.leafSum(node1))