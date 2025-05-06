from typing import List


class MaxConsecutiveOnes:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        result = 0
        curr = 0

        for num in nums:
            if num == 1:
                curr += 1
            else:
                if curr > result:
                    result = curr
                curr = 0

        return max(result, curr)


    # Solution
    def solution(self, nums: List[int]) -> int:
        cnt = 0
        ans = 0

        for num in nums:
            if num == 1:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 0

        return ans
