from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryTreeInorderTraversal:
    ##
    # Iteration
    # - Time Complexity: O(N)
    # - Space Complexity: O(H)
    #
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack: List[TreeNode] = []
        result: List[TreeNode] = []

        while root or len(stack) > 0:
            if root:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                result.append(root.val)
                root = root.right

        return result


    # Solution
    ##
    # Solution 1
    #
    # Recursion
    # - Time Complexity: O(N)
    # - Space Complexity: O(H)
    #
    def solution1(self, root: Optional[TreeNode]) -> List[int]:
        result = []

        def inorder(node: Optional[TreeNode]):
            if not node:
                return

            inorder(node.left)
            result.append(node.val)
            inorder(node.right)

        inorder(root)

        return result

    ##
    # Solution 2
    #
    # Iteration
    # - Time Complexity: O(N)
    # - Space Complexity: O(H)
    #
    def solution2(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        stack = []
        current = root

        while current or stack:
            while current:
                stack.append(current)
                current = current.left

            current = stack.pop()
            result.append(current.val)

            current = current.right

        return result

    ##
    # Solution 3
    #
    # Morris Traversal
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def solution3(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        current = root

        while current:
            if not current.left:
                result.append(current.val)
                current = current.right
            else:
                predecessor = current.left

                while predecessor.right and predecessor.right != current:
                    predecessor = predecessor.right

                if not predecessor.right:
                    predecessor.right = current
                    current = current.left
                else:
                    predecessor.right = None
                    result.append(current.val)
                    current = current.right

        return result
