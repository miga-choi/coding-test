from typing import List


class ThreeSum:
    """
    # Sorting + Two pointers
    #
    # Complexities:
    # - Time Complexity: O(N²)
    # - Space Complexity: O(1)
    """
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)

        result: List[List[int]] = []
        nums_len: int = len(nums)

        for flag in range(nums_len - 2):
            if flag > 0 and nums[flag] == nums[flag - 1]:
                continue

            left: int = flag + 1
            right: int = nums_len - 1

            while left < right:
                sum: int = nums[flag] + nums[left] + nums[right]

                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                else:
                    result.append([nums[flag], nums[left], nums[right]])

                    left += 1
                    right -= 1

                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1

        return result


    # Solution
    """
    # Sorting + Two pointers
    #
    # Complexities:
    # - Time Complexity: O(N²)
    # - Space Complexity: O(1)
    """
    def solution(self, nums: List[int]) -> List[List[int]]:
        results = []

        nums.sort()

        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue

            if nums[i] > 0:
                break

            left, right = i + 1, len(nums) - 1

            while left < right:
                three_sum = nums[i] + nums[left] + nums[right]

                if three_sum < 0:
                    left += 1
                elif three_sum > 0:
                    right -= 1
                else:
                    results.append([nums[i], nums[left], nums[right]])

                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1

        return results
