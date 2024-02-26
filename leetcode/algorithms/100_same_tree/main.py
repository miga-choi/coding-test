from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class SameTree:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p is None and q is None:
            return True
        if p is None or q is None or p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)


    # Best Solution
    # Best Solution 1: Recursive (DFS) Preorder traversal
    def bestSolution1(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # Base case: If both trees are empty, they are identical.
        if not p and not q:
            return True
        # If one of the trees is empty and the other is not, they are not identical.
        if not p or not q:
            return False

        # Compare the values of the current nodes.
        if p.val != q.val:
            return False

        # Recursively check the left and right subtrees.
        return self.bestSolution1(p.left, q.left) and self.bestSolution1(
            p.right, q.right
        )

    # Best Solution 2: Level-order traversal using Queues
    def bestSolution2(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # Create queues for both trees.
        queue1 = deque()
        queue2 = deque()

        # Start by adding the root nodes of both trees to their respective queues.
        queue1.append(p)
        queue2.append(q)

        while queue1 and queue2:
            node1 = queue1.popleft()
            node2 = queue2.popleft()

            # If the values of the current nodes are not equal, the trees are not identical.
            if not node1 and not node2:
                continue
            if not node1 or not node2 or node1.val != node2.val:
                return False

            # Add the left and right children of both nodes to their respective queues.
            queue1.append(node1.left)
            queue1.append(node1.right)
            queue2.append(node2.left)
            queue2.append(node2.right)

        # If both queues are empty, the trees are identical.
        return not queue1 and not queue2

    # Best Solution 3: Level-order traversal using Stack
    def bestSolution3(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        stack1, stack2 = [p], [q]

        while stack1 and stack2:
            node1 = stack1.pop()
            node2 = stack2.pop()

            if not node1 and not node2:
                # Both nodes are None, so they match.
                continue
            elif not node1 or not node2 or node1.val != node2.val:
                # Nodes are not identical, return False.
                return False

            # Push the left children onto the stacks.
            stack1.append(node1.left)
            stack2.append(node2.left)

            # Push the right children onto the stacks.
            stack1.append(node1.right)
            stack2.append(node2.right)

        # If both stacks are empty, and no mismatches have been found, the trees are identical.
        return not stack1 and not stack2

    # Best Solution 4: Tree Hashing
    def bestSolution4(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        hash1 = self.bestSolution4_computeTreeHash(p)
        hash2 = self.bestSolution4_computeTreeHash(q)
        return hash1 == hash2

    def bestSolution4_computeTreeHash(self, node: TreeNode) -> str:
        if node is None:
            return "null"
        left_hash = self.bestSolution4_computeTreeHash(node.left)
        right_hash = self.bestSolution4_computeTreeHash(node.right)
        return f"({node.val}{left_hash}{right_hash})"
