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
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.checkDepth(root) is not -1

    def checkDepth(self, node_: Optional[TreeNode]) -> int:
        if node_ is None:
            return 0

        leftDepth = self.checkDepth(node_.left)
        rightDepth = self.checkDepth(node_.right)

        if leftDepth is -1 or rightDepth is -1:
            return -1
        if abs(leftDepth - rightDepth) > 1:
            return -1

        return max(leftDepth, rightDepth) + 1

    # Best Solution
    def bestSolution(self, root: Optional[TreeNode]) -> bool:
        return self.Height(root) >= 0

    def Height(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return 0
        leftheight, rightheight = self.Height(root.left), self.Height(root.right)
        if leftheight < 0 or rightheight < 0 or abs(leftheight - rightheight) > 1:
            return -1
        return max(leftheight, rightheight) + 1
