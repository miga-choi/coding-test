from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class InvertBinaryTree:
    """
    # Recursiont: DFS
    #
    # Complexities:
    #   N - The Number of nodes in `root`
    #   H - THe Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root == None:
            return None

        temp: Optional[TreeNode] = root.left
        root.left = self.invertTree(root.right)
        root.right = self.invertTree(temp)

        return root


    # Solution
    """
    # Solution 1
    #
    # Recursiont: DFS
    #
    # Complexities:
    #   N - The Number of nodes in `root`
    #   H - THe Height of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(H)
    """
    def solution1(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        
        root.left, root.right = root.right, root.left
        
        self.solution1(root.left)
        self.solution1(root.right)
        
        return root

    """
    # Solution 2
    #
    # Iteration: BFS (Queue)
    #
    # Complexities:
    #   N - The Number of nodes in `root`
    #   W - THe Width of `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(W)
    """
    def solution2(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
            
        queue = deque([root])
        
        while queue:
            node = queue.popleft()
            
            node.left, node.right = node.right, node.left
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
                
        return root
