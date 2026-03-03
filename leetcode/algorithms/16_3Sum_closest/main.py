from typing import List


class ThreeSumClosest:
    """
    # Sorting + Two Pointers
    #
    # Complexities:
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
    """
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()

        n: int = len(nums)
        closest_sum: int = nums[0] + nums[1] + nums[2]

        for flag in range(0, n - 2):
            left: int = flag + 1
            right: int = n - 1

            while left < right:
                curr_sum: int = nums[flag] + nums[left] + nums[right]

                if abs(curr_sum - target) < abs(closest_sum - target):
                    closest_sum = curr_sum

                if curr_sum < target:
                    left += 1
                elif curr_sum > target:
                    right -= 1
                else:
                    return curr_sum

        return closest_sum


    # Solution
    """
    # Sorting + Two Pointers
    #
    # Complexities:
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
    """
    def solution(self, nums: List[int], target: int) -> int:
        nums.sort()

        closest_sum = nums[0] + nums[1] + nums[2]
        n = len(nums)

        for i in range(n - 2):
            left, right = i + 1, n - 1

            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]

                if abs(target - current_sum) < abs(target - closest_sum):
                    closest_sum = current_sum

                if current_sum == target:
                    return current_sum
                elif current_sum < target:
                    left += 1
                else:
                    right -= 1

        return closest_sum
