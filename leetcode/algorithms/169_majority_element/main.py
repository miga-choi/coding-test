from sys import stdin
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        numsMap = {}
        length = len(nums) / 2

        while len(nums) > 0:
            num = nums.pop()
            if numsMap.get(num) is not None and numsMap.get(num) > 0:
                numsMap[num] = numsMap[num] + 1
            else:
                numsMap[num] = 1

            if numsMap[num] > length:
                return num


# Best Solution
import statistics

f = open("user.out", "w")
for line in stdin:
    l = sorted(map(int, line.rstrip()[1:-1].split(",")))
    print(l[len(l) // 2], file=f)
exit(0)
