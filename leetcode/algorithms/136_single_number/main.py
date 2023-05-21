class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for num in nums:
            result = result ^ num
        return result

    # Best Solution
    def bestSolution(self, nums: List[int]) -> int:
        return reduce(lambda total, el: total ^ el, nums)
