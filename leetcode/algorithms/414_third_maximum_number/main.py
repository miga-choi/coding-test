from typing import List


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = list(set(nums))

        if len(nums) > 2:
            for i in range(2):
                nums = list(filter(lambda x: x < max(nums), nums))

        return max(nums)


    # Best Solution
    def bestSolution(self, nums: List[int]) -> int:
        v = [float("-inf"), float("-inf"), float("-inf")]
        for num in nums:
            if num not in v:
                if num > v[0]:
                    v = [num, v[0], v[1]]
                elif num > v[1]:
                    v = [v[0], num, v[1]]
                elif num > v[2]:
                    v = [v[0], v[1], num]
        return max(nums) if float("-inf") in v else v[2]
