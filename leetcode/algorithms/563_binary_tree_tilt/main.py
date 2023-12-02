from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        result = {"val": 0}
        self.getVal(root, result)
        return result["val"]

    def getVal(self, node: Optional[TreeNode], result: dict) -> int:
        if node != None:
            left = self.getVal(node.left, result)
            right = self.getVal(node.right, result)
            result["val"] = result["val"] + abs(left - right)
            return left + right + node.val
        else:
            return 0


    # Best Solution
    def bestSolution1(self, root: Optional[TreeNode]) -> int:
        self.ans = 0

        def _sum(node):
            if not node:
                return 0
            left, right = _sum(node.left), _sum(node.right)
            self.ans += abs(left - right)
            return node.val + left + right

        _sum(root)
        return self.ans

    def bestSolution2(self, root: Optional[TreeNode]) -> int:
        def tilt(root: Optional[TreeNode]) -> (int, int):
            # return (sum, tilt) of tree
            if not root:
                return (0, 0)
            left = tilt(root.left)
            right = tilt(root.right)
            return (
                left[0] + right[0] + root.val,
                abs(left[0] - right[0]) + left[1] + right[1],
            )

        return tilt(root)[1]

    def bestSolution3(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode]) -> List[int]:
            if not node:
                return [0, 0]
            t1, s1 = dfs(node.left)
            t2, s2 = dfs(node.right)
            return [t1 + t2 + abs(s1 - s2), s1 + s2 + node.val]

        return dfs(root)[0]
