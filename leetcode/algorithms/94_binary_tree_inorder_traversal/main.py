from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryTreeInorderTraversal:
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
    # Best Solution 1: DFS Preorder
    def bestSolution1(self, root: Optional[TreeNode]) -> List[int]:
        return (
            [root.val] + self.bestSolution1(root.left) + self.bestSolution1(root.right)
            if root
            else []
        )

    # Best Solution 2: DFS Inorder
    def bestSolution2(self, root: Optional[TreeNode]) -> List[int]:
        return (
            self.bestSolution2(root.left) + [root.val] + self.bestSolution2(root.right)
            if root
            else []
        )

    # Best Solution 3: DFS Postorder
    def bestSolution3(self, root: Optional[TreeNode]) -> List[int]:
        return (
            self.bestSolution3(root.left) + self.bestSolution3(root.right) + [root.val]
            if root
            else []
        )

    # Best Solution 4: Recursively
    def bestSolution4(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        self.helper(root, res)
        return res

    def helper(self, root, res):
        if root:
            self.helper(root.left, res)
            res.append(root.val)
            self.helper(root.right, res)

    # Best Solution 5: Iteratively
    def bestSolution5(self, root: Optional[TreeNode]) -> List[int]:
        res, stack = [], []
        while True:
            while root:
                stack.append(root)
                root = root.left
            if not stack:
                return res
            node = stack.pop()
            res.append(node.val)
            root = node.right
