from typing import List


class LargestNumberAtLeastTwiceOfOthers:
    def dominantIndex(self, nums: List[int]) -> int:
        max: int = -1
        second: int = -1
        index: int = -1

        for i in range(0, len(nums)):
            if nums[i] > max:
                second = max
                max = nums[i]
                index = i
            elif nums[i] > second:
                second = nums[i]

        return index if max >= second * 2 else -1


    # Solution
    def solution(self, nums: List[int]) -> int:
        max: int = -1
        index: int = -1
        second: int = -1

        for i in range(0, len(nums)):
            if nums[i] > max:
                second = max
                max = nums[i]
                index = i
            elif nums[i] > second:
                second = nums[i]

        return index if second * 2 <= max else -1
