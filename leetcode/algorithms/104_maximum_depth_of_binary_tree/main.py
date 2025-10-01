from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class MaximumDepthOfBinaryTree:
    ##
    # Recursion: DFS
    # - Time Complexity: O(N)
    # - Space Complexity: O(H)
    #
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0

        left: int = self.maxDepth(root=root.left)
        right: int = self.maxDepth(root=root.right)

        return max(left, right) + 1


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

        left_depth = self.solution1(root.left)
        right_depth = self.solution1(root.right)

        return 1 + max(left_depth, right_depth)

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

        depth = 0
        queue = deque([root])

        while queue:
            depth += 1

            level_size = len(queue)

            for _ in range(level_size):
                node = queue.popleft()

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        return depth

    ##
    # Solution 3
    #
    # Iteration: DFS (Stack)
    # - Time Complexity: O(N)
    # - Space Complexity: O(H)
    #
    def solution3(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        stack = [(root, 1)]
        max_depth = 0

        while stack:
            node, current_depth = stack.pop()

            if node:
                max_depth = max(max_depth, current_depth)

                stack.append((node.left, current_depth + 1))
                stack.append((node.right, current_depth + 1))

        return max_depth
