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


    # Solution
    # Solution 1: DFS Preorder
    def solution1(self, root: Optional[TreeNode]) -> List[int]:
        return [root.val] + self.solution1(root.left) + self.solution1(root.right) if root else []

    # Solution 2: DFS Inorder
    def solution2(self, root: Optional[TreeNode]) -> List[int]:
        return self.solution2(root.left) + [root.val] + self.solution2(root.right) if root else []

    # Solution 3: DFS Postorder
    def solution3(self, root: Optional[TreeNode]) -> List[int]:
        return self.solution3(root.left) + self.solution3(root.right) + [root.val] if root else []

    # Solution 4: Recursively
    def helper(self, root, res):
        if root:
            self.helper(root.left, res)
            res.append(root.val)
            self.helper(root.right, res)

    def solution4(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        self.helper(root, res)
        return res

    # Solution 5: Iteratively
    def solution5(self, root: Optional[TreeNode]) -> List[int]:
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
