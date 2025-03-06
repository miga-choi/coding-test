from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class MergeTwoBinaryTrees:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if root1 == None:
            return root2
        if root2 == None:
            return root1
        return TreeNode(
            root1.val + root2.val,
            self.mergeTrees(root1=root1.left, root2=root2.left),
            self.mergeTrees(root1=root1.right, root2=root2.right),
        )

    # Solution
    def solution(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root1 and not root2:
            return None
        ans = TreeNode((root1.val if root1 else 0) + (root2.val if root2 else 0))
        ans.left = self.mergeTrees(root1 and root1.left, root2 and root2.left)
        ans.right = self.mergeTrees(root1 and root1.right, root2 and root2.right)
        return ans
