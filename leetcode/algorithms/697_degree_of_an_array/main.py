from typing import List


class DegreeOfAnArray:
    def findShortestSubArray(self, nums: List[int]) -> int:
        numsCountMap: dict[int, int] = {}
        numsFirstIndexMap: dict[int, int] = {}
        maxCount: int = 0
        minSubarrayLength = len(nums)

        for i in range(len(nums)):
            if nums[i] not in numsCountMap:
                numsCountMap[nums[i]] = 0
                numsFirstIndexMap[nums[i]] = i

            count: int = numsCountMap[nums[i]] + 1
            numsCountMap[nums[i]] = count
            if count > maxCount:
                maxCount = count
                minSubarrayLength = i - numsFirstIndexMap[nums[i]] + 1
            elif count == maxCount:
                subarrayLength = i - numsFirstIndexMap[nums[i]] + 1
                if subarrayLength < minSubarrayLength:
                    minSubarrayLength = subarrayLength

        return minSubarrayLength


    # Solution: Left and Right Index
    def findShortestSubArray(self, nums: List[int]) -> int:
        left, right, count = {}, {}, {}
        for i, x in enumerate(nums):
            if x not in left:
                left[x] = i
            right[x] = i
            count[x] = count.get(x, 0) + 1

        ans = len(nums)
        degree = max(count.values())
        for x in count:
            if count[x] == degree:
                ans = min(ans, right[x] - left[x] + 1)

        return ans
