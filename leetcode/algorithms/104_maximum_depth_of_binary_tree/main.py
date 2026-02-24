from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class MaximumDepthOfBinaryTree:
    """
    # Recursion - DFS
    #
    # Complexities:
    #   N - The number of nodes in `root`
    #   H - The heights of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0

        left: int = self.maxDepth(root=root.left)
        right: int = self.maxDepth(root=root.right)

        return max(left, right) + 1


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
    def solution1(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        left_depth = self.solution1(root.left)
        right_depth = self.solution1(root.right)

        return max(left_depth, right_depth) + 1

    """
    # Solution 2
    #
    # Iteration - BFS
    #
    # Complexities:
    #   N - The number of nodes in `root`
    #   H - The heights of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution2(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        queue = deque([root])
        depth = 0

        while queue:
            level_size = len(queue)

            for _ in range(level_size):
                node = queue.popleft()

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)

            depth += 1

        return depth
