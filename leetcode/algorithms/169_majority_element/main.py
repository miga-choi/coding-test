from collections import Counter, defaultdict
from typing import List


class MajorityElement:
    """
    # HashMap
    # 
    # Complexities:
    #   N - `numsSize`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
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


    # Solution
    """
    # Solution 1
    #
    # HashMap
    # 
    # Complexities:
    #   N - `numsSize`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, nums: List[int]) -> int:
        counts = Counter(nums)
        return max(counts.keys(), key=counts.get)

    """
    # Solution 2
    #
    # Sorting
    # 
    # Complexities:
    #   N - `numsSize`
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution2(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums) // 2]

    """
    # Solution 3
    #
    # Boyer-Moore Voting Algorithm
    #
    # Complexities:
    #   N - `numsSize`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution3(self, nums: List[int]) -> int:
        candidate = None
        count = 0
        
        for num in nums:
            if count == 0:
                candidate = num
            
            if num == candidate:
                count += 1
            else:
                count -= 1
                
        return candidate
