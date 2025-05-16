from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class SubtreeOfAnotherTree:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        return self.checkNode(root, subRoot)

    def checkNode(self, node: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if node == None:
            return False
        return (
            self.compareNode(node, subRoot)
            or self.checkNode(node.left, subRoot)
            or self.checkNode(node.right, subRoot)
        )

    def compareNode(self, node1: Optional[TreeNode], node2: Optional[TreeNode]) -> bool:
        if node1 == None and node2 == None:
            return True
        elif node1 == None or node2 == None:
            return False
        else:
            return (
                node1.val == node2.val
                and self.compareNode(node1.left, node2.left)
                and self.compareNode(node1.right, node2.right)
            )


    # Solution
    # Solution 1
    def solution1(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if self.isMatch(root, subRoot):
            return True

        if not root:
            return False

        return self.solution1(root.left, subRoot) or self.solution1(root.right, subRoot)

    def isMatch(self, root, subRoot):
        if not (root and subRoot):
            return root is subRoot

        return (
            root.val == subRoot.val
            and self.isMatch(root.left, subRoot.left)
            and self.isMatch(root.right, subRoot.right)
        )

    # Solution 2: Merkle hashing
    def solution2(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        from hashlib import sha256

        def hash_(x: str) -> str:
            S = sha256()
            S.update(x.encode("utf-8"))
            return S.hexdigest()

        def merkle(node: Optional[TreeNode]) -> str:
            if not node:
                return "#"
                
            m_left = merkle(node.left)
            m_right = merkle(node.right)

            node.merkle = hash_(m_left + str(node.val) + m_right)

            return node.merkle

        merkle(root)
        merkle(subRoot)

        def dfs(node: Optional[TreeNode]) -> bool:
            if not node:
                return False
            return node.merkle == subRoot.merkle or dfs(node.left) or dfs(node.right)

        return dfs(root)
