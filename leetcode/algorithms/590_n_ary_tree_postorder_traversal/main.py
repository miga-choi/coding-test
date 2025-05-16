from typing import List


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class NAryTreePostorderTraversal:
    def postorder(self, root: "Node") -> List[int]:
        return self.traversal(root, [])

    def traversal(self, node: "Node", list: List[int]) -> List[int]:
        if node == None:
            return list

        for child in node.children:
            self.traversal(child, list)

        list.append(node.val)

        return list


    # Solution
    # Solution 1: Recursion
    def solution1(self, root: "Node") -> List[int]:
        res = []

        if root == None:
            return res

        def recursion(root: "Node", res: List[int]):
            for child in root.children:
                recursion(child, res)
            res.append(root.val)

        recursion(root, res)

        return res

    # Solution 2: Iteration
    def solution2(self, root: "Node") -> List[int]:
        res = []

        if root == None:
            return res

        stack = [root]

        while stack:
            curr = stack.pop()
            res.append(curr.val)
            stack.extend(curr.children)

        return res[::-1]
