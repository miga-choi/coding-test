# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
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

    # Best Solution
    def bestSolution(self, root):
        # Base case...
        if not root:
            return []
        # Create an array list to store the solution result...
        sol = []
        # Create an empty stack and push the root node...
        bag = [root]
        # Loop till stack is empty...
        while bag:
            # Pop a node from the stack...
            node = bag.pop()
            sol.append(node.val)
            # Push the left child of the popped node into the stack...
            if node.left:
                bag.append(node.left)
            # Append the right child of the popped node into the stack...
            if node.right:
                bag.append(node.right)
        return sol[::-1]  # Return the solution list...
