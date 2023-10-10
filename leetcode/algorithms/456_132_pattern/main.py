from typing import List
import sys


class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        stack = []
        third = -1 * 10**9
        while len(nums) > 0:
            num = nums.pop()
            if num < third:
                return True
            while len(stack) > 0 and stack[-1] < num:
                third = stack.pop()
            stack.append(num)
        return False


    # Best Solution
    def bestSolution(self, nums: List[int]) -> bool:
        stack = []
        s3 = -sys.maxint
        for n in nums[::-1]:
            if n < s3:
                return True
            while stack and stack[-1] < n:
                s3 = stack.pop()
            stack.append(n)
        return False
