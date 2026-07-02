from typing import List


class SummaryRanges:
    """
    # Two Pointers
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def summaryRanges(self, nums: List[int]) -> List[str]:
        result = []

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
    """
    # Two Pointers
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution(self, nums: List[int]) -> List[str]:
        ans = []
        i = 0
        n = len(nums)
        
        while i < n:
            j = i
            while j + 1 < n and nums[j + 1] == nums[j] + 1:
                j += 1
            
            if i == j:
                ans.append(str(nums[i]))
            else:
                ans.append(f"{nums[i]}->{nums[j]}")
                
            i = j + 1
            
        return ans
