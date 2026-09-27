from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class SumOfLeftLeaves:
    """
    # Recursion (DFS)
    #
    # Complexities:
    #   N - The Numbder of Nodes in `root`
    #   H - The Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0

        result = 0

        if root.left != None:
            if root.left.left == None and root.left.right == None:
                result += root.left.val
            else:
                result += self.sumOfLeftLeaves(root.left)

        result += self.sumOfLeftLeaves(root.right)

        return result


    # Solution
    """
    # Solution 1
    #
    # Recursion (DFS)
    #
    # Complexities:
    #   N - The Numbder of Nodes in `root`
    #   H - The Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution1(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        total = 0

        if root.left:
            if not root.left.left and not root.left.right:
                total += root.left.val
            else:
                total += self.solution1(root.left)

        total += self.solution1(root.right)

        return total

    """
    # Solution 2
    #
    # Recursion (DFS) with Flag
    #
    # Complexities:
    #   N - The Numbder of Nodes in `root`
    #   H - The Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution2(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode], is_left: bool) -> int:
            if not node:
                return 0

            if not node.left and not node.right:
                return node.val if is_left else 0

            return dfs(node.left, True) + dfs(node.right, False)

        return dfs(root, False)

    """
    # Solution 3
    #
    # Iteration (BFS) with Stack
    #
    # Complexities:
    #   N - The Numbder of Nodes in `root`
    #   W - The Width of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(W)
    """
    def solution3(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        stack = [(root, False)]
        total = 0

        while stack:
            node, is_left = stack.pop()

            if not node.left and not node.right:
                if is_left:
                    total += node.val

                continue

            if node.left:
                stack.append((node.left, True))

            if node.right:
                stack.append((node.right, False))

        return total
