from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class MinimumDistanceBetweenBSTNodes:
    def inorderTraversal(self, node: Optional[TreeNode], vals: List[int]):
        if node == None:
            return

        self.inorderTraversal(node=node.left, vals=vals)
        vals.append(node.val)
        self.inorderTraversal(node=node.right, vals=vals)

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        vals: List[int] = []

        self.inorderTraversal(node=root, vals=vals)

        min: int = 10e5

        for i in range(0, len(vals) - 1):
            diff: int = vals[i + 1] - vals[i]
            if diff < min:
                min = diff

        return min


    # Solution
    pre = -float("inf")
    res = float("inf")

    def solution(self, root: Optional[TreeNode]) -> int:
        if root.left:
            self.minDiffInBST(root.left)

        self.res = min(self.res, root.val - self.pre)
        self.pre = root.val

        if root.right:
            self.minDiffInBST(root.right)

        return self.res
