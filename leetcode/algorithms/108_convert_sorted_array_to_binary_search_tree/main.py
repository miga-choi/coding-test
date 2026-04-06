import math
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class ConvertSortedArrayToBinarySearchTree:
    """
    # Divide-and-conquer
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(logᴺ)
    """
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if nums is None or len(nums) is 0:
            return None

        mid = math.floor(len(nums) / 2)

        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[0:mid])
        root.right = self.sortedArrayToBST(nums[mid + 1 :])

        return root


    # Solution
    """
    # Divide-and-conquer
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(logᴺ)
    """
    def solution(self, nums: List[int]) -> Optional[TreeNode]:
        def build_bst(left: int, right: int) -> Optional[TreeNode]:
            if left > right:
                return None
            
            mid = (left + right) // 2
            
            node = TreeNode(nums[mid])
            
            node.left = build_bst(left, mid - 1)
            node.right = build_bst(mid + 1, right)
            
            return node
        
        return build_bst(0, len(nums) - 1)
