from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class CountCompleteTreeNodes:
    """
    # DFS
    #
    # Complexities:
    #   N - Number of nodes in `root`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(logᴺ)
    """
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        return self.countNodes(root.left) + self.countNodes(root.right) + 1


    # Solution
    """
    # Perfect Binary Tree
    #
    # Complexities:
    #   N - Number of nodes in `root`
    #   - Time Complexity: O(log₂ᴺ)
    #   - Space Complexity: O(logᴺ)
    """
    def solution(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        def get_left_height(node: Optional[TreeNode]) -> int:
            height = 0
            while node:
                height += 1
                node = node.left
            return height
            
        def get_right_height(node: Optional[TreeNode]) -> int:
            height = 0
            while node:
                height += 1
                node = node.right
            return height
            
        left_h = get_left_height(root)
        right_h = get_right_height(root)
        
        if left_h == right_h:
            return (1 << left_h) - 1
            
        return 1 + self.solution(root.left) + self.solution(root.right)
