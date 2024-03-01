from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class MaximumDepthOfBinaryTree:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        return self.returnDepth(0, root)

    def returnDepth(self, depth_: int, node_: Optional[TreeNode]) -> int:
        depth = depth_ + 1
        if node_.left is not None:
            leftDepth = self.returnDepth(depth_ + 1, node_.left)
            if leftDepth > depth:
                depth = leftDepth
        if node_.right is not None:
            rightDepth = self.returnDepth(depth_ + 1, node_.right)
            if rightDepth > depth:
                depth = rightDepth
        return depth


    # Best Solution
    # Best Solution 1: RECURSIVE DFS
    def bestSolution1(self, root: Optional[TreeNode]) -> int:
        def dfs(root, depth):
            if not root:
                return depth
            return max(dfs(root.left, depth + 1), dfs(root.right, depth + 1))

        return dfs(root, 0)

    # Best Solution 2: Recursive
    def bestSolution2(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return max(self.bestSolution2(root.left), self.bestSolution2(root.right)) + 1

    # Best Solution 3: Iterative
    def bestSolution3(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        worklist = deque([root])
        num_node_level = 1
        levels = 0
        while worklist:
            node = worklist.popleft()
            if node.left:
                worklist.append(node.left)
            if node.right:
                worklist.append(node.right)
            num_node_level -= 1
            if num_node_level == 0:
                levels += 1
                num_node_level = len(worklist)

        return levels
