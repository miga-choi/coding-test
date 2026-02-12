from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryTreeInorderTraversal:
    """
    # Iteration
    #
    # Complexities:
    #   N - Size of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack: List[TreeNode] = []
        result: List[TreeNode] = []

        while root or len(stack) > 0:
            if root:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                result.append(root.val)
                root = root.right

        return result


    # Solution
    """
    # Solution 1
    #
    # Recursion
    #
    # Complexities:
    #   N - Size of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, root: Optional[TreeNode]) -> List[int]:
        result = []

        def dfs(node):
            if not node:
                return

            dfs(node.left)

            result.append(node.val)

            dfs(node.right)

        dfs(root)
        return result

    """
    # Solution 2
    #
    # Iteration
    #
    # Complexities:
    #   N - Size of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        stack = []
        current = root

        while current or stack:
            while current:
                stack.append(current)
                current = current.left

            current = stack.pop()

            result.append(current.val)

            current = current.right

        return result
