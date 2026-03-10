from collections import deque
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryTreeLevelOrderTraversal:
    """
    # BFS
    #
    # Complexities:
    #   N - Size of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result: List[List[int]] = list()

        if root == None:
            return result

        q: deque = deque()
        q.append(root)

        while len(q) > 0:
            array: List[int] = list()

            for _ in range(0, len(q)):
                node: Optional[TreeNode] = q.popleft()

                array.append(node.val)

                if node.left != None:
                    q.append(node.left)
                if node.right != None:
                    q.append(node.right)

            result.append(array)

        return result


    # Solution
    """
    # Solution 1
    #
    # BFS
    #
    # Complexities:
    #   N - Size of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        result = []
        queue = deque([root])

        while queue:
            level_size = len(queue)
            current_level = []

            for _ in range(level_size):
                node = queue.popleft()
                current_level.append(node.val)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            result.append(current_level)

        return result

    """
    # Solution 2
    #
    # DFS
    #
    # Complexities:
    #   N - Size of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []

        def dfs(node, level):
            if not node:
                return

            if len(result) == level:
                result.append([])

            result[level].append(node.val)

            dfs(node.left, level + 1)
            dfs(node.right, level + 1)

        dfs(root, 0)
        return result
