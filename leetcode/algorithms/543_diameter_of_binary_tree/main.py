from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class DiameterOfBinaryTree:
    """
    Recursion: DFS (Bottom-up)
    - Time Complexity: O(N)
    - Space Complexity: O(H)
    """
    max_diameter: int = 0

    def getMaxDiameter(self, node: TreeNode) -> int:
        if node == None:
            return 0

        left_diameter: int = self.getMaxDiameter(node=node.left)
        right_diameter: int = self.getMaxDiameter(node=node.right)

        if left_diameter + right_diameter > self.max_diameter:
            self.max_diameter = left_diameter + right_diameter

        return max(left_diameter, right_diameter) + 1

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.getMaxDiameter(root)
        return self.max_diameter


    # Solution
    """
    Recursion: DFS (Bottom-up)
    - Time Complexity: O(N)
    - Space Complexity: O(H)
    """
    def solution(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0

        def depth(node: Optional[TreeNode]) -> int:
            if not node:
                return 0

            left_depth = depth(node.left)
            right_depth = depth(node.right)

            self.diameter = max(self.diameter, left_depth + right_depth)

            return 1 + max(left_depth, right_depth)

        depth(root)

        return self.diameter
