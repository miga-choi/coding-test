from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryTreePostorderTraversal:
    """
    * Iteration
    *
    * Complexities:
    *   N - Number of nodes in `root`
    *   H - Height of `root`
    *   - Time Complexity: O(N)
    *   - Space Complexity: O(H)
    """
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        nodes = []

        if root is not None:
            nodes.append(root)

            while len(nodes) > 0:
                node = nodes.pop()
                result.append(node.val)

                if node.left is not None:
                    nodes.append(node.left)

                if node.right is not None:
                    nodes.append(node.right)

        result.reverse()
        return result


    # Solution
    """
    * Solution 1
    *
    * Recursion
    *
    * Complexities:
    *   N - Number of nodes in `root`
    *   H - Height of `root`
    *   - Time Complexity: O(N)
    *   - Space Complexity: O(H)
    """
    def solution1(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        
        def traverse(node):
            if not node:
                return
            
            traverse(node.left)
            
            traverse(node.right)
            
            result.append(node.val)
            
        traverse(root)
        return result

    """
    * Solution 2
    *
    * Iteration
    *
    * Complexities:
    *   N - Number of nodes in `root`
    *   H - Height of `root`
    *   - Time Complexity: O(N)
    *   - Space Complexity: O(H)
    """
    def solution2(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
            
        result = []
        stack = [root]
        
        while stack:
            node = stack.pop()
            
            result.append(node.val)
            
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
                
        return result[::-1]
