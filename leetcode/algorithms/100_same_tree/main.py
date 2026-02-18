from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class SameTree:
    """
    # Recursion - DFS
    #
    # Complexities:
    #   M - The number of nodes in `p`
    #   N - The number of nodes in `q`
    #   Hp - The heights of `p`
    #   Hq - The heights of `q`
    #   - Time Complexity: O(min(M, N))
    #   - Space Complexity: O(min(Hp, Hq))
    """
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p is None and q is None:
            return True

        if p is None or q is None or p.val != q.val:
            return False

        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)


    # Solution
    """
    # Solution 1
    #
    # Recursion - DFS
    #
    # Complexities:
    #   M - The number of nodes in `p`
    #   N - The number of nodes in `q`
    #   Hp - The heights of `p`
    #   Hq - The heights of `q`
    #   - Time Complexity: O(min(M, N))
    #   - Space Complexity: O(min(Hp, Hq))
    """
    def solution1(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True

        if not p or not q:
            return False

        if p.val != q.val:
            return False

        return self.solution1(p.left, q.left) and self.solution1(p.right, q.right)

    """
    # Solution 2
    #
    # Iteration - BFS
    #
    # Complexities:
    #   M - The number of nodes in `p`
    #   N - The number of nodes in `q`
    #   Hp - The heights of `p`
    #   Hq - The heights of `q`
    #   - Time Complexity: O(min(M, N))
    #   - Space Complexity: O(min(Hp, Hq))
    """
    def solution2(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        queue = deque([(p, q)])

        while queue:
            node_p, node_q = queue.popleft()

            if not node_p and not node_q:
                continue

            if not node_p or not node_q or node_p.val != node_q.val:
                return False

            queue.append((node_p.left, node_q.left))
            queue.append((node_p.right, node_q.right))

        return True
