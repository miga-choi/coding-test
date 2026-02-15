from typing import Optional
import sys


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class ValidateBinarySearchTree:
    """
    # Recursion: DFS
    #
    # Complexities:
    #   N - Size of `node`
    #   H - Height of `node`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def helper(self, node: Optional[TreeNode], min_val: int, max_val: int):
        if node == None:
            return True

        if node.val <= min_val or node.val >= max_val:
            return False

        return self.helper(node.left, min_val, node.val) and self.helper(node.right, node.val, max_val)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root, -sys.maxsize - 1, sys.maxsize)


    # Solution
    """
    # Solution 1
    #
    # Recursive with Range
    #
    # Complexities:
    #   N - Size of `node`
    #   H - Height of `node`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution1(self, root: Optional[TreeNode]) -> bool:
        def validate(node: Optional[TreeNode], low: float, high: float) -> bool:
            if not node:
                return True

            if not (low < node.val < high):
                return False

            return (validate(node.left, low, node.val) and validate(node.right, node.val, high))

        return validate(root, float('-inf'), float('inf'))

    """
    # Solution 2
    #
    # Inorder Traversal
    #
    # Complexities:
    #   N - Size of `node`
    #   H - Height of `node`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution2(self, root: Optional[TreeNode]) -> bool:
        stack = []
        prev = float('-inf')
        current = root

        while stack or current:
            while current:
                stack.append(current)
                current = current.left

            current = stack.pop()

            if current.val <= prev:
                return False

            prev = current.val
            current = current.right

        return True
