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
    def preorder(root):
        return [root.val] + preorder(root.left) + preorder(root.right) if root else []

    def inorder(root):
        return inorder(root.left) + [root.val] + inorder(root.right) if root else []

    def postorder(root):
        return postorder(root.left) + postorder(root.right) + [root.val] if root else []
