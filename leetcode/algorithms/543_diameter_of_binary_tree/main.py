from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class DiameterOfBinaryTree:
    result = 0

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.getMaxNode(root)

        return self.result

    def getMaxNode(self, node: TreeNode) -> int:
        if node == None:
            return 0

        left = self.getMaxNode(node.left)
        right = self.getMaxNode(node.right)

        self.result = max(self.result, left + right)

        return max(left, right) + 1


    # Solution
    # Solution 1
    def solution1(self, root: Optional[TreeNode]) -> int:
        self.ans = 0

        def depth(p):
            if not p:
                return 0
            left, right = depth(p.left), depth(p.right)
            self.ans = max(self.ans, left + right)
            return 1 + max(left, right)

        depth(root)
        return self.ans

    # Solution 2: Implementation
    def solution2(self, root: Optional[TreeNode]) -> int:
        # Implement depth
        def depth(node: Optional[TreeNode]) -> int:
            return 1 + max(depth(node.left), depth(node.right)) if node else 0

        return depth(root.left) + depth(root.right)  # calculate diameter

    # Solution 3
    diameter: int

    def __init__(self):
        self.diameter = 0  # stores the maximum diameter calculated

    def depth(self, node: Optional[TreeNode]) -> int:
        """
        This function needs to do the following:
            1. Calculate the maximum depth of the left and right sides of the given node
            2. Determine the diameter at the given node and check if its the maximum
        """
        # Calculate maximum depth
        left = self.depth(node.left) if node.left else 0
        right = self.depth(node.right) if node.right else 0
        # Calculate diameter
        if left + right > self.diameter:
            self.diameter = left + right
        # Make sure the parent node(s) get the correct depth from this node
        return 1 + (left if left > right else right)

    def solution3(self, root: Optional[TreeNode]) -> int:
        # if not root:
        #     return 0
        self.depth(root)  # root is guaranteed to be a TreeNode object
        return self.diameter
