from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class MinimumDepthOfBinaryTree:
    """
    # Recursion: DFS
    #
    # Complexities:
    #   N - Number of nodes in `root`
    #   H - Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        left_depth: int = self.minDepth(root.left)
        right_depth: int = self.minDepth(root.right)

        if left_depth == 0 or right_depth == 0:
            return max(left_depth, right_depth) + 1

        return min(left_depth, right_depth) + 1


    # Solution
    """
    # Solution 1
    #
    # Iteration: BFS (Queue)
    #
    # Complexities:
    #   N - Number of nodes in `root`
    #   W - Width of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(W)
    """
    def solution1(self, root: Optional[TreeNode]) -> int:
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
                
        return 0

    """
    # Solution 2
    #
    # Recursion: DFS
    #
    # Complexities:
    #   N - Number of nodes in `root`
    #   H - Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution2(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        if not root.left and not root.right:
            return 1
        
        if not root.left:
            return self.solution2(root.right) + 1
        if not root.right:
            return self.solution2(root.left) + 1
        
        return min(self.solution2(root.left), self.solution2(root.right)) + 1
