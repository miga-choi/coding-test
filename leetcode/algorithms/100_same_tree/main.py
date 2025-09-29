from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class SameTree:
    ##
    # Recursion: DFS
    # - Time Complexity: O(N)
    # - Space Complexity: O(H)
    #
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p is None and q is None:
            return True

        if p is None or q is None or p.val != q.val:
            return False

        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)


    # Solution
    ##
    # Solution 1
    #
    # Recursion: DFS
    # - Time Complexity: O(N)
    # - Space Complexity: O(H)
    #
    def solution1(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True

        if not p or not q or p.val != q.val:
            return False

        return self.solution1(p.left, q.left) and self.solution1(p.right, q.right)

    ##
    # Solution 2
    #
    # Iteration: DFS (Stack)
    # - Time Complexity: O(N)
    # - Space Complexity: O(H)
    #
    def solution2(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        stack = [(p, q)]

        while stack:
            node_p, node_q = stack.pop()

            if not node_p and not node_q:
                continue

            if not node_p or not node_q or node_p.val != node_q.val:
                return False

            stack.append((node_p.right, node_q.right))
            stack.append((node_p.left, node_q.left))

        return True

    ##
    # Solution 3
    #
    # Iteration: BFS (Queue)
    # - Time Complexity: O(N)
    # - Space Complexity: O(W)
    #
    def solution3(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        queue = deque([(p, q)])

        while queue:
            node_p, node_q = queue.popleft()

            if not self.check(node_p, node_q):
                return False

            if node_p and node_q:
                queue.append((node_p.left, node_q.left))
                queue.append((node_p.right, node_q.right))

        return True
