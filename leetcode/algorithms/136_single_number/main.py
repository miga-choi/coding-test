from typing import List


class SingleNumber:
    ##
    # Bit Manipulation
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def singleNumber(self, nums: List[int]) -> int:
        result = 0

        for num in nums:
            result = result ^ num

        return result
