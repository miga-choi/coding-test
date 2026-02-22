from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class SymmetricTree:
    """
    # Recursion - DFS
    #
    # Complexities:
    #   N - The number of nodes in `root`
    #   H - The heights of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        return self.checkNode(root.left, root.right)

    def checkNode(self, leftNode: Optional[TreeNode], rightNode: Optional[TreeNode]) -> bool:
        if leftNode is None and rightNode is None:
            return True

        if (leftNode is None and rightNode is not None) or (leftNode is not None and rightNode is None):
            return False

        if leftNode is not None and rightNode is not None:
            if leftNode.val != rightNode.val:
                return False
            else:
                return self.checkNode(leftNode.left, rightNode.right) and self.checkNode(leftNode.right, rightNode.left)

        return False


    # Solution
    """
    # Solution 1
    #
    # Recursion - DFS
    #
    # Complexities:
    #   N - The number of nodes in `root`
    #   H - The heights of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution1(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        return self.isMirror(root.left, root.right)

    def isMirror(self, t1: Optional[TreeNode], t2: Optional[TreeNode]) -> bool:
        if not t1 and not t2:
            return True

        if not t1 or not t2:
            return False

        if t1.val != t2.val:
            return False

        return self.isMirror(t1.left, t2.right) and self.isMirror(t1.right, t2.left)

    """
    # Solution 2
    #
    # Iteration
    #
    # Complexities:
    #   N - The number of nodes in `root`
    #   H - The heights of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution2(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        queue = deque([(root.left, root.right)])

        while queue:
            t1, t2 = queue.popleft()

            if not t1 and not t2:
                continue

            if not t1 or not t2 or t1.val != t2.val:
                return False

            queue.append((t1.left, t2.right))
            queue.append((t1.right, t2.left))

        return True
