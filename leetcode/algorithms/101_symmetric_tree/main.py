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
    def checkNode(
        self, leftNode: Optional[TreeNode], rightNode: Optional[TreeNode]
    ) -> bool:
        if leftNode is None and rightNode is None:
            return True
        if (leftNode is None and rightNode is not None) or (
            leftNode is not None and rightNode is None
        ):
            return False
        if leftNode is not None and rightNode is not None:
            if leftNode.val != rightNode.val:
                return False
            else:
                return self.checkNode(
                    leftNode.left, rightNode.right
                ) and self.checkNode(leftNode.right, rightNode.left)
        return False

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        return self.checkNode(root.left, root.right)

    # Best Solution
    def bestSolution(self, root):
        # Special case...
        if not root:
            return true
        # Return the function recursively...
        return self.isSame(root.left, root.right)

    # A tree is called symmetric if the left subtree must be a mirror reflection of the right subtree...
    def isSame(self, leftroot, rightroot):
        # If both root nodes are null pointers, return true...
        if leftroot == None and rightroot == None:
            return True
        # If exactly one of them is a null node, return false...
        if leftroot == None or rightroot == None:
            return False
        # If root nodes haven't same value, return false...
        if leftroot.val != rightroot.val:
            return False
        # Return true if the values of root nodes are same and left as well as right subtrees are symmetric...
        return self.isSame(leftroot.left, rightroot.right) and self.isSame(
            leftroot.right, rightroot.left
        )
