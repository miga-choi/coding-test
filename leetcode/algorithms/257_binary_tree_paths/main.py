from collections import deque
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryTreePaths:
    """
    # DFS + Backtracking
    #
    # Complexities:
    #   N - The number of nodes in `root`
    #   H - The height of tree in `root`
    #   - Time Complexity: O(N * H)
    #   - Space Complexity: O(H)
    """
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if root == None:
            return []

        if root.left == None and root.right == None:
            return [f"{root.val}"]

        leftArray = self.binaryTreePaths(root.left)
        rightArray = self.binaryTreePaths(root.right)

        left = list(map(lambda v_: f"{root.val}->{v_}", leftArray))
        right = list(map(lambda v_: f"{root.val}->{v_}", rightArray))

        return left + right


    # Solution
    """
    # Solution 1
    #
    # DFS + Backtracking
    #
    # Complexities:
    #   N - The number of nodes in `root`
    #   H - The height of tree in `root`
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(H)
    """
    def solution1(self, root: Optional[TreeNode]) -> List[str]:
        result = []

        def dfs(node: Optional[TreeNode], path: List[str]):
            if not node:
                return

            path.append(str(node.val))

            if not node.left and not node.right:
                result.append("->".join(path))
            else:
                if node.left:
                    dfs(node.left, path)
                if node.right:
                    dfs(node.right, path)

            path.pop()

        dfs(root, [])

        return result

    """
    # Solution 2
    #
    # BFS
    #
    # Complexities:
    #   N - The number of nodes in `root`
    #   H - The height of tree in `root`
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(N * H)
    """
    def solution2(self, root: Optional[TreeNode]) -> List[str]:
        if not root:
            return []
            
        result = []
        queue = deque([(root, str(root.val))])
        
        while queue:
            node, path = queue.popleft()
            
            if not node.left and not node.right:
                result.append(path)
                continue
                
            if node.left:
                queue.append((node.left, path + "->" + str(node.left.val)))
            if node.right:
                queue.append((node.right, path + "->" + str(node.right.val)))
                
        return result
