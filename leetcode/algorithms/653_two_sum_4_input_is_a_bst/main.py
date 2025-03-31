from typing import List
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class TwoSum4InputIsABST:
    def inorder(self, node: Optional[TreeNode], valArray: List[int]):
        if node != None:
            self.inorder(node=node.left, valArray=valArray)
            valArray.append(node.val)
            self.inorder(node=node.right, valArray=valArray)

    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        valArray: List[int] = []

        self.inorder(node=root, valArray=valArray)

        left: int = 0
        right: int = len(valArray) - 1

        while left < right:
            sum: int = valArray[left] + valArray[right]
            if sum < k:
                left += 1
            elif sum > k:
                right -= 1
            else:
                return True

        return False

    # Solution: HashSet
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        def dfs(root, seen):
            if root == None:
                return False
            complement = k - root.val
            if complement in seen:
                return True
            seen.add(root.val)
            return dfs(root.left, seen) or dfs(root.right, seen)

        return dfs(root, set())
