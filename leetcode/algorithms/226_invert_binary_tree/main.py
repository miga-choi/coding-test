from typing import Optional


class InvertBinaryTree:
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root != None:
            tempNode = self.invertTree(root.left)
            root.left = self.invertTree(root.right)
            root.right = tempNode
            return root
        return root


    # Solution
    def solution(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # Base Case
        if not root:
            return root

        # Call the left substree
        self.solution(root.left)

        # Call the right substree
        self.solution(root.right)

        # Swap the nodes
        root.left, root.right = root.right, root.left

        # Return the root
        return root
