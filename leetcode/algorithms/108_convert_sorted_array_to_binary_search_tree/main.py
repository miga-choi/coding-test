import math
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class ConvertSortedArrayToBinarySearchTree:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if nums is None or len(nums) is 0:
            return None

        mid = math.floor(len(nums) / 2)

        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[0:mid])
        root.right = self.sortedArrayToBST(nums[mid + 1 :])

        return root


    # Solution
    # Solution 1: Recursion
    def solution1(self, nums: List[int]) -> Optional[TreeNode]:
        total_nums = len(nums)
        if not total_nums:
            return None

        mid_node = total_nums // 2
        return TreeNode(
            nums[mid_node],
            self.solution1(nums[:mid_node]),
            self.solution1(nums[mid_node + 1 :]),
        )

    # Solution 2: Recursion
    def solution2(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None

        mid = len(nums) // 2

        root = TreeNode(nums[mid])
        root.left = self.solution2(nums[:mid])
        root.right = self.solution2(nums[mid + 1 :])

        return root

    # Solution 3:
    def solution3(self, nums: List[int]) -> Optional[TreeNode]:
        def convert(left, right):
            if left > right:
                return None
            mid = (left + right) // 2
            node = TreeNode(nums[mid])
            node.left = convert(left, mid - 1)
            node.right = convert(mid + 1, right)
            return node

        return convert(0, len(nums) - 1)
