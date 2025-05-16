class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class MaximumDepthOfNAryTree:
    def maxDepth(self, root: 'Node') -> int:
        if root == None:
            return 0

        maxNum = 0

        for child in root.children:
            maxNum = max(maxNum, self.maxDepth(child))

        return maxNum + 1


    # Solution
    def solution(self, root: 'Node') -> int:
        # Base case
        if root == None:
            return 0

        # Depth level of the tree
        depth = 0

        # Loops through children array
        for child in root.children:
            # Compares current depth of depth with a new level of depth
            # Sets the biggest value to variable depth
            depth = max(depth, self.maxDepth(child))

        # As going deeper into the tree increases depth by 1
        return depth + 1
