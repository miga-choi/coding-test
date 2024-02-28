from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class SymmetricTree:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        return self.checkNode(root.left, root.right)

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


    # Best Solution
    # Best Solution 1:
    def bestSolution1(self, root: Optional[TreeNode]) -> bool:
        # Special case...
        if not root:
            return True
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

    # Best Solution 2: Recursively
    def bestSolution2(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        else:
            return self.isMirror(root.left, root.right)

    def isMirror(self, left, right):
        if left is None and right is None:
            return True

        if left is None or right is None:
            return False

        if left.val == right.val:
            outPair = self.isMirror(left.left, right.right)
            inPiar = self.isMirror(left.right, right.left)
            return outPair and inPiar
        else:
            return False

    # Best Solution 3: Iterativey
    def bestSolution3(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        stack = [[root.left, root.right]]

        while len(stack) > 0:
            pair = stack.pop(0)
            left = pair[0]
            right = pair[1]

            if left is None and right is None:
                continue
            if left is None or right is None:
                return False
            if left.val == right.val:
                stack.insert(0, [left.left, right.right])
                stack.insert(0, [left.right, right.left])
            else:
                return False

        return True
