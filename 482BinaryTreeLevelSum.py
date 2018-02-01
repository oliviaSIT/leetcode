"""
http://www.lintcode.com/en/problem/binary-tree-level-sum/
Definition of TreeNode:
time: 10min think 5min learn from answer 15min test
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    """
    @param: root: the root of the binary tree
    @param: level: the depth of the target level
    @return: An integer
    """
    def levelSum(self, root, level):
        # write your code here

        p = []

        self.dfs(root, p, 1, level)

        return sum(p)

    def dfs(self, root, p, depth, level):
        if root is None:
            return

        if depth == level:
            p.append(root.val)
            return
        self.dfs(root.left, p, depth + 1, level)
        self.dfs(root.right, p, depth + 1, level)



node1, node2, node3, node4, node5 = TreeNode(1), TreeNode(2), TreeNode(4), TreeNode(2), TreeNode(3)
node1.left = node2
node1.right = node3
node2.left = node4
node2.right = node5

n = 2
ans = Solution()
print(ans.levelSum(node1, n))