from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryTreePreorderTraversal:
    """
    # Iteration
    #
    # Complexities:
    #   N - Number of nodes in `root`
    #   H - Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        totalNodes = []

        if root is not None:
            totalNodes.append(root)

            while len(totalNodes) > 0:
                node = totalNodes.pop()
                result.append(node.val)

                if node.right is not None:
                    totalNodes.append(node.right)

                if node.left is not None:
                    totalNodes.append(node.left)

        return result


    # Solution
    """
    # Solution 1
    #
    # Recursion
    #
    # Complexities:
    #   N - Number of nodes in `root`
    #   H - Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution1(self, root: Optional[TreeNode]) -> List[int]:
        result = []

        def traverse(node):
            if not node:
                return

            result.append(node.val)

            traverse(node.left)

            traverse(node.right)

        traverse(root)

        return result

    """
    # Solution 2
    #
    # Iteration
    #
    # Complexities:
    #   N - Number of nodes in `root`
    #   H - Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution2(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        result = []
        stack = [root]

        while stack:
            node = stack.pop()

            result.append(node.val)

            if node.right:
                stack.append(node.right)

            if node.left:
                stack.append(node.left)

        return result
