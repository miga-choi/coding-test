from typing import List


class RemoveElement:
    """
    # Two Pointers
    #
    # Complexities:
    #   N - Length of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def removeElement(self, nums: List[int], val: int) -> int:
        nums[:] = sorted(filter(lambda num: num != val, nums))

        return len(nums)


    # Solution
    """
    # Two Pointers
    #
    # Complexities:
    #   N - Length of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution(self, nums: List[int], val: int) -> int:
        k = 0

        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1

        return k
