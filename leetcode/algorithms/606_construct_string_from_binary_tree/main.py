from typing import Optional


class Solution:
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

    def tree2str(self, root: Optional[TreeNode]) -> str:
        if root == None:
            return ""

        if root.left == None and root.right == None:
            return f"{root.val}"

        left = "()"
        if root.left != None:
            left = f"({self.tree2str(root.left)})"

        right = ""
        if root.right != None:
            right = f"({self.tree2str(root.right)})"

        return f"{root.val}{left}{right}"

    # Best Solution
    def bestSolution(self, root: Optional[TreeNode]) -> str:
        return ""
