# Definition for a binary tree node.
from typing import Optional


class MinimumAbsoluteDifferenceInBST:
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        array = []
        min = 10**5

        def bstToArray(node):
            if node != None:
                bstToArray(node.left)
                array.append(node.val)
                bstToArray(node.right)

        bstToArray(root)

        for i in range(1, len(array)):
            diff = abs(array[i - 1] - array[i])
            if diff < min:
                min = diff

        return min


    # Solution
    # Solution 1
    def solution1(self, root: Optional[TreeNode]) -> int:
        def fn(node, lo, hi):
            if not node:
                return hi - lo
            left = fn(node.left, lo, node.val)
            right = fn(node.right, node.val, hi)
            return min(left, right)

        return fn(root, float("-inf"), float("inf"))

    # Solution 2
    def solution2(self, root: Optional[TreeNode]) -> int:
        L = []

        def dfs(node):
            if node.left:
                dfs(node.left)
            L.append(node.val)
            if node.right:
                dfs(node.right)

        dfs(root)
        return min(b - a for a, b in zip(L, L[1:]))
