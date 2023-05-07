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
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if nums is None or len(nums) is 0:
            return None

        mid = math.floor(len(nums) / 2)

        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[0:mid])
        root.right = self.sortedArrayToBST(nums[mid + 1 :])

        return root

    # Best Solution
    # recursive
    def bestSolution(self, nums):
        def rec(nums, start, end):
            if start <= end:
                mid = (start + end) // 2
                node = TreeNode(nums[mid])
                node.left = rec(nums, start, mid - 1)
                node.right = rec(nums, mid + 1, end)
                return node

        return rec(nums, 0, len(nums) - 1)
