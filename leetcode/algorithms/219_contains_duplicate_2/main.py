from typing import List


class ContainsDuplicateII:
    """
    # Hash Map
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        numsMap = {}

        for i in range(len(nums)):
            if numsMap.get(nums[i]) != None:
                if abs(i - numsMap[nums[i]]) <= k:
                    return True
            numsMap.update({nums[i]: i})

        return False


    # Solution
    """
    # Solution 1
    #
    # Sliding Window + Hash Set
    #
    # Complexities:
    #   N - Size of `nums`
    #   K - `k`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(min(N, K))
    """
    def solution1(self, nums: List[int], k: int) -> bool:
        seen = set()

        for i, num in enumerate(nums):
            if num in seen:
                return True

            seen.add(num)

            if len(seen) > k:
                seen.remove(nums[i - k])

        return False

    """
    # Solution 2
    #
    # Hash Map
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, nums: List[int], k: int) -> bool:
        num_to_index = {}

        for i, num in enumerate(nums):
            if num in num_to_index and i - num_to_index[num] <= k:
                return True

            num_to_index[num] = i

        return False
