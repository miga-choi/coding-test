import collections
from typing import List


class LongestHarmoniousSubsequence:
    def findLHS(self, nums: List[int]) -> int:
        result: int = 0
        numsMap: dict = {}

        for num in nums:
            if numsMap.get(num) == None:
                numsMap.update({num: 1})
            else:
                numsMap.update({num: numsMap.get(num) + 1})

        if len(numsMap) <= 1:
            return 0

        for k, _ in numsMap.items():
            l = numsMap.get(k - 1) or 0
            r = numsMap.get(k + 1) or 0
            if l > 0 or r > 0:
                result = max(result, numsMap.get(k) + l, numsMap.get(k) + r)

        return result


    # Solution
    # Solution 1
    def solution1(self, nums: List[int]) -> int:
        count = collections.Counter(nums)
        ans = 0
        for x in count:
            if x + 1 in count:
                ans = max(ans, count[x] + count[x + 1])
        return ans

    # Solution 2
    def solution2(self, nums: List[int]) -> int:
        C = collections.Counter(nums)
        return max((C[n] + C[n + 1]) * (C[n + 1] != 0) for n in C)
