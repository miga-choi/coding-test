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
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False
        if root.left is None and root.right is None:
            return root.val == targetSum
        else:
            return self.hasPathSum(root.left, targetSum - root.val) or self.hasPathSum(root.right, targetSum - root.val)

    # Best Solution

    # I. DFS recursive solution
    # Algorithm:
    #   1. Visit a node and check that node is leaf and node.val == sum. If it's true - return True, else continue traverse
    #   2. Traverse the left subtree and decrease current sum by value of current node , i.e., call hasPathSum(node.left, curr_sum - node.val)
    #   3. Traverse the right subtree and decrease current sum by value of current node , i.e., call hasPathSum(node.right, curr_sum - node.val)
    def bestSolution1(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        if not root.left and not root.right and root.val == sum:
            return True
        return self.bestSolution1(root.left, sum - root.val) or self.bestSolution1(root.right, sum - root.val)

    # II. DFS iterative solution
    # Algorithm:
    #   1. Create empty stack and push root node and current sum to stack.
    #   2. Do followind steps while stack is not empty:
    #     - Pop (node, curr_sum) from stack
    #     - Cheack that node is leaf and node.val == sum. If it's true - return True, else go to the next step
    #     - Push left child of popped node and current sum decreased by popped node value (node.left, curr_sum - node.val).
    #     - Push right child of popped node and current sum decreased by popped node value (node.right, curr_sum - node.val).
    #     - Return False if sum is not found.
    def bestSolution2(self, root: TreeNode, sum: int) -> bool:
        stack = [(root, sum)]
        while stack:
            node, curr_sum = stack.pop()
        if not node:
            continue
        if not node.left and not node.right and curr_sum == node.val:
            return True
        stack.append((node.left, curr_sum - node.val))
        stack.append((node.right, curr_sum - node.val))
        return False

    # III. BFS Solution
    # Algorithm:
    #   1. Create empty deque (double-ended queue) and push root node and current sum to queue.
    #   2. Do followind steps while queue is not empty:
    #     - Do popfront/popleft (node, curr_sum) from queue
    #     - If node is None - continue
    #     - Cheack that node is leaf and node.val == sum. If it's true - return True, else go to the next step
    #     - Push left child of popped node and current sum decreased by popped node value (node.left, curr_sum - node.val) to the queue.
    #     - Push right child of popped node and current sum decreased by popped node value (node.right, curr_sum - node.val) to the queue.
    #   3. Return False if sum is not found.
    from collections import deque

    def bestSolution3(self, root: TreeNode, sum: int) -> bool:
        deq = deque()
        deq.append((root, sum))
        while deq:
            node, curr_sum = deq.popleft()
            if not node:
                continue
            if not node.left and not node.right and curr_sum == node.val:
                return True
            deq.append((node.left, curr_sum - node.val))
            deq.append((node.right, curr_sum - node.val))
        return False
