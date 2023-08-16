from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if root == None:
            return []

        if root.left == None and root.right == None:
            return [f"{root.val}"]

        leftArray = self.binaryTreePaths(root.left)
        rightArray = self.binaryTreePaths(root.right)

        left = list(map(lambda v_: f"{root.val}->{v_}", leftArray))
        right = list(map(lambda v_: f"{root.val}->{v_}", rightArray))

        return left + right


    # Best Solution
    def bestSolution(self, root: TreeNode) -> List[str]:
        result = []

        # ----------------------------------------
        def helper(node, cur):
            if not node:
                # base case
                return

            if not node.left and not node.right:
                # stop condition
                result.append(cur + [str(node.val)])

            else:
                # general case
                helper(node.left, cur + [str(node.val)])
                helper(node.right, cur + [str(node.val)])

        # ----------------------------------------

        helper(node=root, cur=[])
        return [*map("->".join, result)]
