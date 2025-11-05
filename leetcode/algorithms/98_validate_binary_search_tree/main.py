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
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
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
    # Recursion: DFS
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    """
    def solution1(self, root: Optional[TreeNode]) -> bool:
        def validate(node, low=-float("inf"), high=float("inf")):
            if not node:
                return True

            if not (low < node.val < high):
                return False

            return validate(node.left, low, node.val) and validate(node.right, node.val, high)

        return validate(root)

    """
    # Solution 2
    #
    # Iteration: Inorder Traversal
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    """
    def solution2(self, root: Optional[TreeNode]) -> bool:
        inorder_result = []

        def inorder(node):
            if not node:
                return

            inorder(node.left)
            inorder_result.append(node.val)
            inorder(node.right)

        inorder(root)

        for i in range(len(inorder_result) - 1):
            if inorder_result[i] >= inorder_result[i + 1]:
                return False

        return True

    """
    # Solution 3
    #
    # Iteration: Inorder Traversal
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    """
    def solution3(self, root: Optional[TreeNode]) -> bool:
        self.prev_val = -float('inf')

        def inorder(node):
            if not node:
                return True

            if not inorder(node.left):
                return False

            if node.val <= self.prev_val:
                return False

            self.prev_val = node.val

            return inorder(node.right)

        return inorder(root)
