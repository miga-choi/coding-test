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
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        totalNodes = []
        if root is not None:
            totalNodes.append(root)

            while len(totalNodes) > 0:
                node = totalNodes.pop()
                result.append(node.val)

                if node.right is not None:
                    totalNodes.append(node.right)

                if node.left is not None:
                    totalNodes.append(node.left)

        return result

    # Best Solution
    # The iterative version
    def bestSolution1(self, root: Optional[TreeNode]) -> List[int]:
                                          #  Ex: root = [1, 2,None, 3,4]
        if not root:                      #
            return []                     #         1
        stack, ans = [root], []           #        /
                                          #       2
        while stack:                      #      / \
            node = stack.pop()            #     3   4
            ans.append(node.val)          #
                                          #     node     node.left   node.right  stack    ans
            if node.right:                #   –––––––––  –––––––––   –––––––––   ––––––  ––––––
                stack.append(node.right)  #                                       [1]     []
            if node.left:                 #       1          2         None       [2]     [1]
                stack.append(node.left)   #       2          3          4         [4,3]   [1,2]
                                          #       3        None        None       [4]     [1,2,3]
                                          #       4        None        None       [4]     [1,2,3,4]
        return ans

    # The recursive version
    def bestSolution2(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(node):
            if not node:
                return

            ans.append(node.val)

            dfs(node.left)
            dfs(node.right)

            return

        ans = []

        dfs(root)

        return ans

    # And here's a one-liner:
    def bestSolution3(self, root: TreeNode) -> list[int]:
        return [] if not root else ([root.val]+self.preorderTraversal(root.left)+self.preorderTraversal(root.right))