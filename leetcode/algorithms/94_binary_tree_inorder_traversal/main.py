from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        totalRoots = []
        result = []
        while root or len(totalRoots) > 0:
            if root:
                totalRoots.append(root)
                root = root.left
            else:
                root = totalRoots.pop()
                result.append(root.val)
                root = root.right
        return result


    # Best Solution
    def preorder(self, root: Optional[TreeNode]) -> List[int]:
        return [root.val] + self.preorder(root.left) + self.preorder(root.right) if root else []

    def inorder(self, root: Optional[TreeNode]) -> List[int]:
        return self.inorder(root.left) + [root.val] + self.inorder(root.right) if root else []

    def postorder(self, root: Optional[TreeNode]) -> List[int]:
        return self.postorder(root.left) + self.postorder(root.right) + [root.val] if root else []
