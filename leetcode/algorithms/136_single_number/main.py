from functools import reduce
from typing import List


class SingleNumber:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for num in nums:
            result = result ^ num
        return result


    # Solution
    def solution(self, nums: List[int]) -> int:
        return reduce(lambda total, el: total ^ el, nums)
