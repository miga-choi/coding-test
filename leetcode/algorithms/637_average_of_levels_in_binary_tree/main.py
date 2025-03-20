from typing import List
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class AverageOfLevelsInBinaryTree:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        result: List[float] = []
        queue: List[TreeNode] = []

        queue.append(root)
        while len(queue) > 0:
            nodeCount: int = len(queue)
            sum: float = 0
            for i in range(nodeCount):
                node: TreeNode = queue.pop(0)
                sum += node.val
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
            result.append(sum / nodeCount)

        return result

    # Solution
    def solution(self, root: Optional[TreeNode]) -> List[float]:
        q, ans = [root], []
        while len(q):
            qlen, row = len(q), 0
            for i in range(qlen):
                curr = q.pop(0)
                row += curr.val
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            ans.append(row / qlen)
        return ans
