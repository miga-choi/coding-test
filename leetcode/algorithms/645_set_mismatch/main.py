from typing import List


class SetMismatch:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        duplicatedNum: int = -1
        missedNum: int = -1

        for i in range(1, len(nums) + 1):
            count: int = 0
            for num in nums:
                if num == i:
                    count += 1
            if count == 2:
                duplicatedNum = i
            if count == 0:
                missedNum = i

        return [duplicatedNum, missedNum]

    # Solution
    def solution(self, nums: List[int]) -> List[int]:
        dup, missing = -1, -1

        for i in range(1, len(nums) + 1):
            count = nums.count(i)
            if count == 2:
                dup = i
            elif count == 0:
                missing = i

        return [dup, missing]
