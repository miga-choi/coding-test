from typing import Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        return self.returnDepth(0, root)

    def returnDepth(self, depth_: int, node_: Optional[TreeNode]) -> int:
        depth = depth_ + 1
        if node_.left is not None:
            leftDepth = self.returnDepth(depth_ + 1, node_.left)
            if leftDepth > depth:
                depth = leftDepth
        if node_.right is not None:
            rightDepth = self.returnDepth(depth_ + 1, node_.right)
            if rightDepth > depth:
                depth = rightDepth
        return depth


    # Best Solution
    def bestSolution(self, root: Optional[TreeNode]) -> int:
        def dfs(root, depth):
            if not root:
                return depth
            return max(dfs(root.left, depth + 1), dfs(root.right, depth + 1))

        return dfs(root, 0)
