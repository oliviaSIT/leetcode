"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None



class Solution:
    """
    @param: root: the root of binary tree
    @param: target: An integer
    @return: all valid paths
    """
    def binaryTreePathSum(self, root, target):
        # write your code here
        path = []
        result = []
        self.dfs(root, path, result, 0, target)
        return result

    def dfs(self, root, path, result, len, target):
        if root == None:
            return

        path.append(root.val)
        len += root.val

        if root.left == None or root.right == None or len == target:
            result.append(path[:])

        self.dfs(root.left, path, result, len, target)
        self.dfs(root.right, path, result, len, target)

        path.pop()

node1, node2, node3, node4, node5 = TreeNode(1), TreeNode(2), TreeNode(4), TreeNode(2), TreeNode(3)
node1.left = node2
node1.right = node3
node2.left = node4
node2.right = node5

ans = Solution()
print(ans.binaryTreePathSum(node1, 5))