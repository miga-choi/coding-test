from typing import List


class SummaryRanges:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        result = []
        x = 0

        if len(nums) > 0:
            num = nums[0]
            numArray = [num]

            for i in range(1, len(nums)):
                if nums[i] - num == 1:
                    numArray.append(nums[i])
                else:
                    if len(numArray) > 1:
                        result.append(f"{numArray[0]}->{numArray.pop()}")
                    else:
                        result.append(f"{numArray[0]}")
                    numArray = [nums[i]]
                num = nums[i]

            if len(numArray) > 0:
                if len(numArray) > 1:
                    result.append(f"{numArray[0]}->{numArray.pop()}")
                else:
                    result.append(f"{numArray[0]}")

        return result


    # Solution
    def solution(self, nums: List[int]) -> List[str]:
        result = []
        start, end = 0, 0

        while start < len(nums) and end < len(nums):
            if (end + 1) < len(nums) and nums[end] + 1 == nums[end + 1]:
                end = end + 1
            else:
                if nums[start] == nums[end]:
                    result.append(str(nums[start]))
                    start = start + 1
                    end = end + 1
                else:
                    result.append(str(nums[start]) + "->" + str(nums[end]))
                    end = end + 1
                    start = end

        return result
