from typing import List


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def preorder(self, root: "Node") -> List[int]:
        return self.getVal(root, [])

    def getVal(self, node: "Node", list: List[int]) -> List[int]:
        if node != None:
            list.append(node.val)
            for child in node.children:
                self.getVal(child, list)
        return list


    # Best Solution
    # Best Solution 1: Iterative
    def bestSolution1(self, root: "Node", output: List[int] = []) -> List[int]:
        if root is None:
            return []

        stack = [root]
        output = []

        # Till there is element in stack the loop runs.
        while stack:
            # pop the last element from the stack and store it into temp.
            temp = stack.pop()

            # append. the value of temp to output
            output.append(temp.val)

            # add the children of the temp into the stack in reverse order.
            # children of 1 = [3,2,4], if not reveresed then 4 will be popped out first from the stack.
            # if reversed then stack = [4,2,3]. Here 3 will pop out first.
            # This continues till the stack is empty.
            stack.extend(temp.children[::-1])

        # return the output
        return output

    # Best Solution 2: Recursive
    def bestSolution2(self, root: "Node") -> List[int]:
        output = []

        # perform dfs on the root and get the output stack
        self.dfs(root, output)

        # return the output of all the nodes.
        return output

    def dfs(self, root: "Node", output: List[int]):
        # If root is none return
        if root is None:
            return

        # for preorder we first add the root val
        output.append(root.val)

        # Then add all the children to the output
        for child in root.children:
            self.dfs(child, output)
