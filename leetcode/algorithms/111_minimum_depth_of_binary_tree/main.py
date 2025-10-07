from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class MinimumDepthOfBinaryTree:
    ##
    # Recursion: DFS
    # - Time Complexity: O(N)
    # - Space Complexity: O(H)
    #
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        left_depth: int = self.minDepth(root.left)
        right_depth: int = self.minDepth(root.right)

        if left_depth == 0 or right_depth == 0:
            return max(left_depth, right_depth) + 1

        return min(left_depth, right_depth) + 1


    # Solution
    ##
    # Solution 1
    #
    # Recursion: DFS
    # - Time Complexity: O(N)
    # - Space Complexity: O(H)
    #
    def solution1(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        left_depth = self.minDepth(root.left)
        right_depth = self.minDepth(root.right)

        if not root.left or not root.right:
            return 1 + left_depth + right_depth

        return 1 + min(left_depth, right_depth)

    ##
    # Solution 2
    #
    # Iteration: BFS (Queue)
    # - Time Complexity: O(N)
    # - Space Complexity: O(W)
    #
    def solution2(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        queue = deque([(root, 1)])

        while queue:
            node, depth = queue.popleft()

            if not node.left and not node.right:
                return depth

            if node.left:
                queue.append((node.left, depth + 1))
            if node.right:
                queue.append((node.right, depth + 1))
