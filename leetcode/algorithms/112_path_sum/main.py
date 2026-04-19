from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class PathSum:
    """
    # Recursion - DFS
    #
    # Complexities:
    #   N - Number of nodes in `root`
    #   H - Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False

        if root.left is None and root.right is None:
            return root.val == targetSum

        return self.hasPathSum(root.left, targetSum - root.val) or self.hasPathSum(root.right, targetSum - root.val)


    # Solution
    """
    # Solution 1
    #
    # Recursion - DFS
    #
    # Complexities:
    #   N - Number of nodes in `root`
    #   H - Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, root: TreeNode, targetSum: int) -> bool:
        if not root:
            return False

        if not root.left and not root.right:
            return targetSum == root.val

        remaining_sum = targetSum - root.val
        return (self.hasPathSum(root.left, remaining_sum) or self.hasPathSum(root.right, remaining_sum))

    """
    # Solution 2
    #
    # Iteration - DFS with Stack
    #
    # Complexities:
    #   N - Number of nodes in `root`
    #   H - Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, root: TreeNode, targetSum: int) -> bool:
        if not root:
            return False

        stack = [(root, targetSum - root.val)]

        while stack:
            node, current_sum = stack.pop()

            if not node.left and not node.right and current_sum == 0:
                return True

            if node.right:
                stack.append((node.right, current_sum - node.right.val))

            if node.left:
                stack.append((node.left, current_sum - node.left.val))

        return False
