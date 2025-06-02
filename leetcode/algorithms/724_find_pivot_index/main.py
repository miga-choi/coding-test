from typing import List


class FindPivotIndex:
    def pivotIndex(self, nums: List[int]) -> int:
        leftSum: int = 0
        rightSum: int = sum(nums)

        for i in range(len(nums)):
            rightSum -= nums[i]

            if leftSum == rightSum:
                return i

            leftSum += nums[i]

        return -1


    # Solution
    def Solution(self, nums: List[int]) -> int:
        # Initialize leftSum & rightSum to store
        # the sum of all the numbers strictly to
        # the index's left & right respectively
        leftSum, rightSum = 0, sum(nums)

        # Traverse elements through the loop
        for idx, ele in enumerate(nums):
            rightSum -= ele

            # If the sum of all the numbers strictly to
            # the left of the index is equal to the sum of
            # all the numbers strictly to the index's right
            if leftSum == rightSum:
                # Return the pivot index
                return idx

            leftSum += ele

        # If there is no index that satisfies
        # the conditions in the problem statement
        return -1
