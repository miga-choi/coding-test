from collections import Counter
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class FindModeInBinarySearchTree:
    """
    # In-order Traversal to Array + Two-Pass Run Counting
    #
    # Complexities:
    #   n - The Number of Nodes in `root`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(n)
    """
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
    """
    # Solution 1
    #
    # In-order Traversal to Array + Two-Pass Run Counting
    #
    # Complexities:
    #   n - The Number of Nodes in `root`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(n)
    """
    def solution1(self, root: Optional[TreeNode]) -> List[int]:
        count = Counter()
        stack = [root]

        while stack:
            node = stack.pop()
            count[node.val] += 1
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

        max_count = max(count.values())

        return [val for val, c in count.items() if c == max_count]

    """
    # Solution 2
    #
    # In-order Traversal
    #
    # Complexities:
    #   n - The Number of Nodes in `root`
    #   h - The Height of `root`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(h)
    """
    def solution2(self, root: Optional[TreeNode]) -> List[int]:
        prev = None
        count = max_count = 0
        modes = []

        def visit(val: int) -> None:
            nonlocal prev, count, max_count, modes
            count = count + 1 if val == prev else 1
            prev = val
            if count > max_count:
                max_count = count
                modes = [val]
            elif count == max_count:
                modes.append(val)

        stack, node = [], root
        while stack or node:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            visit(node.val)
            node = node.right

        return modes

    """
    # Solution 3
    #
    # Morris Traversal
    #
    # Complexities:
    #   n - The Number of Nodes in `root`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(n)
    """
    def solution3(self, root: Optional[TreeNode]) -> List[int]:
        prev = None
        count = max_count = 0
        modes = []

        def visit(val: int) -> None:
            nonlocal prev, count, max_count, modes
            count = count + 1 if val == prev else 1
            prev = val

            if count > max_count:
                max_count = count
                modes = [val]
            elif count == max_count:
                modes.append(val)

        cur = root

        while cur:
            if not cur.left:
                visit(cur.val)
                cur = cur.right
            else:
                pred = cur.left

                while pred.right and pred.right is not cur:
                    pred = pred.right

                if not pred.right:
                    pred.right = cur
                    cur = cur.left
                else:
                    pred.right = None
                    visit(cur.val)
                    cur = cur.right

        return modes
