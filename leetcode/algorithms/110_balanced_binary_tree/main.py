from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BalancedBinaryTree:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.checkDepth(root) is not -1

    def checkDepth(self, node_: Optional[TreeNode]) -> int:
        if node_ is None:
            return 0

        leftDepth = self.checkDepth(node_.left)
        rightDepth = self.checkDepth(node_.right)

        if leftDepth is -1 or rightDepth is -1:
            return -1
        if abs(leftDepth - rightDepth) > 1:
            return -1

        return max(leftDepth, rightDepth) + 1


    # Solution
    # Solution 1: Recursion
    def solution1(self, root: Optional[TreeNode]) -> bool:
        def check(root: Optional[TreeNode]):
            if root is None:
                return 0
            left = check(root.left)
            right = check(root.right)
            if left == -1 or right == -1 or abs(left - right) > 1:
                return -1
            return 1 + max(left, right)

        return check(root) != -1

    # Solution 2: Iterative (Postorder traversal)
    def solution2(self, root: Optional[TreeNode]) -> bool:
        stack, node, last, depths = [], root, None, {}
        while stack or node:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack[-1]
                if not node.right or last == node.right:
                    node = stack.pop()
                    left, right = depths.get(node.left, 0), depths.get(node.right, 0)
                    if abs(left - right) > 1:
                        return False
                    depths[node] = 1 + max(left, right)
                    last = node
                    node = None
                else:
                    node = node.right
        return True

    # Solution 3: Iterative (Postorder traversal)
    def solution3(self, root: Optional[TreeNode]) -> bool:
        return self.solution3_height(root) >= 0

    def solution3_height(self, root: Optional[TreeNode]):
        if root is None:
            return 0
        leftheight = self.solution3_height(root.left)
        rightheight = self.solution3_height(root.right)
        if leftheight < 0 or rightheight < 0 or abs(leftheight - rightheight) > 1:
            return -1
        return max(leftheight, rightheight) + 1
