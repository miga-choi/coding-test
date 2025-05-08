from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class SearchInABinarySearchTree:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root != None:
            if root.val == val:
                return root

            left: Optional[TreeNode] = self.searchBST(root=root.left, val=val)
            if left != None:
                return left

            right: Optional[TreeNode] = self.searchBST(
                root=root.right, val=val)
            if right != None:
                return right

        return None


    # Solution
    # Solution 1: Recursion
    def solution1(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root == None:
            return root

        if root.val == val:
            return root

        return self.solution1(root=root.left, val=val) if root.val > val else self.solution1(root=root.right, val=val)

    # Solution 2: Iteration
    def solution2(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        while root != None and root.val != val:
            root = self.solution2(root=root.left, val=val) if root.val > val else self.solution2(root=root.right, val=val)
        return root
