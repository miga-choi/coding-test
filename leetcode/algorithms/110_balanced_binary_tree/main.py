from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BalancedBinaryTree:
    """
    # DFS
    #
    # Complexities:
    #   N - Number of `node`
    #   H - Height of `node`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def checkDepth(self, node: Optional[TreeNode]) -> int:
        if node is None:
            return 0

        leftDepth = self.checkDepth(node.left)

        if leftDepth < 0:
            return -1

        rightDepth = self.checkDepth(node.right)

        if rightDepth < 0:
            return -1

        if abs(leftDepth - rightDepth) > 1:
            return -1

        return max(leftDepth, rightDepth) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.checkDepth(root) != -1


    # Solution
    """
    # DFS
    #
    # Complexities:
    #   N - Number of `node`
    #   H - Height of `node`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution(self, root: Optional[TreeNode]) -> bool:
        def check_height(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            
            left_height = check_height(node.left)
            if left_height == -1:
                return -1
            
            right_height = check_height(node.right)
            if right_height == -1:
                return -1
            
            if abs(left_height - right_height) > 1:
                return -1
            
            return max(left_height, right_height) + 1
            
        return check_height(root) != -1
