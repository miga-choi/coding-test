from typing import List


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def postorder(self, root: "Node") -> List[int]:
        return self.traversal(root, [])

    def traversal(self, node: "Node", list: List[int]) -> List[int]:
        if node == None:
            return list
        for child in node.children:
            self.traversal(child, list)
        list.append(node.val)
        return list


    # Best Solution
    # Best Solution 1: Recursion
    def bestSolution1(self, root: "Node") -> List[int]:
        res = []
        if root == None:
            return res

        def recursion(root: "Node", res: List[int]):
            for child in root.children:
                recursion(child, res)
            res.append(root.val)

        recursion(root, res)
        return res

    # Best Solution 2: Iteration
    def bestSolution2(self, root: "Node") -> List[int]:
        res = []
        if root == None:
            return res

        stack = [root]
        while stack:
            curr = stack.pop()
            res.append(curr.val)
            stack.extend(curr.children)

        return res[::-1]
