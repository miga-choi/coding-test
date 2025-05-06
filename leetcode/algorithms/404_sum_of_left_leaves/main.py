from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class SumOfLeftLeaves:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0

        result = 0

        if root.left != None:
            if root.left.left == None and root.left.right == None:
                result += root.left.val
            else:
                result += self.sumOfLeftLeaves(root.left)

        result += self.sumOfLeftLeaves(root.right)

        return result


    # Solution
    def solution(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        # does this node have a left child which is a leaf?
        if root.left and not root.left.left and not root.left.right:
            # gotcha
            return root.left.val + self.solution(root.right)

        # no it does not have a left child or it's not a leaf
        else:
            # bummer
            return self.solution(root.left) + self.solution(root.right)
