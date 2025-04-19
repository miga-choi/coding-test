from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class PathSum:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False
        if root.left is None and root.right is None:
            return root.val == targetSum
        else:
            return self.hasPathSum(root.left, targetSum - root.val) or self.hasPathSum(root.right, targetSum - root.val)


    # Solution
    # Solution 1: Recursion
    def solution1(self, root: TreeNode, targetSum: int) -> bool:
        if not root:
            return False

        if not root.left and not root.right and root.val == targetSum:
            return True

        targetSum -= root.val

        return self.solution1(root.left, targetSum) or self.solution1(root.right, targetSum)

    # Solution 2: DFS Recursively
    def solution2_dfs(self, root: TreeNode, target: int, res: list):
        if root:
            if not root.left and not root.right and root.val == target:
                res.append(True)
            if root.left:
                self.solution2_dfs(root.left, target - root.val, res)
            if root.right:
                self.solution2_dfs(root.right, target - root.val, res)

    def solution2(self, root: TreeNode, targetSum: int) -> bool:
        res = []
        self.solution2_dfs(root, targetSum, res)
        return any(res)

    # Solution 3: DFS with stack
    def solution3(self, root: TreeNode, targetSum: int) -> bool:
        if not root:
            return False
        stack = [(root, root.val)]
        while stack:
            curr, val = stack.pop()
            if not curr.left and not curr.right and val == targetSum:
                return True
            if curr.right:
                stack.append((curr.right, val + curr.right.val))
            if curr.left:
                stack.append((curr.left, val + curr.left.val))
        return False

    # Solution 4: BFS with queue
    def solution4(self, root: TreeNode, targetSum: int) -> bool:
        if not root:
            return False
        queue = [(root, targetSum - root.val)]
        while queue:
            curr, val = queue.pop(0)
            if not curr.left and not curr.right and val == 0:
                return True
            if curr.left:
                queue.append((curr.left, val - curr.left.val))
            if curr.right:
                queue.append((curr.right, val - curr.right.val))
        return False

    # Solution 5:
    def solution5(self, root: TreeNode, targetSum: int) -> bool:
        if not root:
            return False
        if not root.left and not root.right and root.val == targetSum:
            return True
        return self.solution5(root.left, targetSum - root.val) or self.solution5(root.right, targetSum - root.val)

    # Solution 6:
    # I. DFS recursive solution
    # Algorithm:
    #   1. Visit a node and check that node is leaf and node.val == sum. If it's true - return True, else continue traverse
    #   2. Traverse the left subtree and decrease current sum by value of current node , i.e., call hasPathSum(node.left, curr_sum - node.val)
    #   3. Traverse the right subtree and decrease current sum by value of current node , i.e., call hasPathSum(node.right, curr_sum - node.val)
    def solution6(self, root: TreeNode, targetSum: int) -> bool:
        if not root:
            return False
        if not root.left and not root.right and root.val == targetSum:
            return True
        return self.solution6(root.left, targetSum - root.val) or self.solution6(root.right, targetSum - root.val)

    # Solution 7:
    # II. DFS iterative solution
    # Algorithm:
    #   1. Create empty stack and push root node and current sum to stack.
    #   2. Do followind steps while stack is not empty:
    #     - Pop (node, curr_sum) from stack
    #     - Cheack that node is leaf and node.val == sum. If it's true - return True, else go to the next step
    #     - Push left child of popped node and current sum decreased by popped node value (node.left, curr_sum - node.val).
    #     - Push right child of popped node and current sum decreased by popped node value (node.right, curr_sum - node.val).
    #     - Return False if sum is not found.
    def solution7(self, root: TreeNode, targetSum: int) -> bool:
        stack = [(root, targetSum)]
        while stack:
            node, curr_sum = stack.pop()
            if not node:
                continue
            if not node.left and not node.right and curr_sum == node.val:
                return True
            stack.append((node.left, curr_sum - node.val))
            stack.append((node.right, curr_sum - node.val))
        return False

    # Solution 8:
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
    def solution8(self, root: TreeNode, targetSum: int) -> bool:
        deq = deque()
        deq.append((root, targetSum))
        while deq:
            node, curr_sum = deq.popleft()
            if not node:
                continue
            if not node.left and not node.right and curr_sum == node.val:
                return True
            deq.append((node.left, curr_sum - node.val))
            deq.append((node.right, curr_sum - node.val))
        return False
