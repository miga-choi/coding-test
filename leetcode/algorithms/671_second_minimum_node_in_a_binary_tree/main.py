from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class SecondMinimumNodeInABinaryTree:
    def returnSecondMinimumValue(self, node: Optional[TreeNode], minVal: int) -> int:
        if node == None:
            return -1

        if node.val > minVal:
            return node.val

        left: int = self.returnSecondMinimumValue(node.left, node.val)
        right: int = self.returnSecondMinimumValue(node.right, node.val)

        if left == -1:
            return right
        if right == -1:
            return left

        return min(left, right)

    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        return self.returnSecondMinimumValue(root, root.val)

    # Solution
    def solution(self, root: Optional[TreeNode]) -> int:
        res = [float('inf')]

        def traverse(node):
            if not node:
                return
            if root.val < node.val < res[0]:
                res[0] = node.val
            traverse(node.left)
            traverse(node.right)

        traverse(root)

        return -1 if res[0] == float('inf') else res[0]
