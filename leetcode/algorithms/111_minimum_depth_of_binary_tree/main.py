import collections
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class MinimumDepthOfBinaryTree:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        if root.left is None and root.right is None:
            return 1

        if root.left is None:
            return self.minDepth(root.right) + 1

        if root.right is None:
            return self.minDepth(root.left) + 1

        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1


    # Best Solution
    # Best Solution 1: DFS
    def bestSolution1(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        if None in [root.left, root.right]:
            return (
                max(self.bestSolution1(root.left), self.bestSolution1(root.right)) + 1
            )
        else:
            return (
                min(self.bestSolution1(root.left), self.bestSolution1(root.right)) + 1
            )

    # Best Solution 2: BFS
    def bestSolution2(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        queue = collections.deque([(root, 1)])
        while queue:
            node, level = queue.popleft()
            if node:
                if not node.left and not node.right:
                    return level
                else:
                    queue.append((node.left, level + 1))
                    queue.append((node.right, level + 1))

    # Best Solution 3
    def bestSolution3(self, root: Optional[TreeNode]) -> int:
        # Base case...
        # If the subtree is empty i.e. root is NULL, return depth as 0...
        if root is None:
            return 0

        # Initialize the depth of two subtrees...
        leftDepth = self.bestSolution3(root.left)
        rightDepth = self.bestSolution3(root.right)

        # If the both subtrees are empty...
        if root.left is None and root.right is None:
            return 1

        # If the left subtree is empty, return the depth of right subtree after adding 1 to it...
        if root.left is None:
            return 1 + rightDepth

        # If the right subtree is empty, return the depth of left subtree after adding 1 to it...
        if root.right is None:
            return 1 + leftDepth

        # When the two child function return its depth...
        # Pick the minimum out of these two subtrees and return this value after adding 1 to it...
        # Adding 1 is the current node which is the parent of the two subtrees...
        return min(leftDepth, rightDepth) + 1
