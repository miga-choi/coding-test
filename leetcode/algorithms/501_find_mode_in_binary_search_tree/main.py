from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class FindModeInBinarySearchTree:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        map = {}
        result = []

        def checkNode(node: TreeNode):
            if node == None:
                return

            if node.left != None:
                checkNode(node.left)

            if node.right != None:
                checkNode(node.right)

            if map.get(node.val) == None:
                map.update({node.val: 1})
            else:
                map.update({node.val: map.get(node.val) + 1})

        checkNode(root)

        for i in range(len(list(map.values()))):
            if list(map.values())[i] >= max(list(map.values())):
                result.append(list(map.keys())[i])

        return result


    # Solution
    prev = None
    max_count = 0
    current_count = 0
    result = []

    def solution(self, root: Optional[TreeNode]) -> List[int]:
        self.dfs(root)
        return self.result

    def dfs(self, node):
        if not node:
            return

        self.dfs(node.left)

        self.current_count = 1 if node.val != self.prev else self.current_count + 1

        if self.current_count == self.max_count:
            self.result.append(node.val)
        elif self.current_count > self.max_count:
            self.result = [node.val]
            self.max_count = self.current_count

        self.prev = node.val

        self.dfs(node.right)
