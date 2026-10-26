from typing import List


class OneThreeTwoPattern:
    """
    # Monotonic Stack
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
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


    # Solution
    """
    # Solution 1
    #
    # Brute Force
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N³)
    #   - Space Complexity: O(1)
    """
    def solution1(self, nums: List[int]) -> bool:
        n = len(nums)

        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if nums[i] < nums[k] < nums[j]:
                        return True

        return False

    """
    # Solution 2
    #
    # Prefix Minimum
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N³)
    #   - Space Complexity: O(1)
    """
    def solution2(self, nums: List[int]) -> bool:
        n = len(nums)
        min_i = nums[0]

        for j in range(1, n):
            for k in range(j + 1, n):
                if min_i < nums[k] < nums[j]:
                    return True

            min_i = min(min_i, nums[j])

        return False

    """
    # Solution 3
    #
    # Monotonic Stack
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution3(self, nums: List[int]) -> bool:
        stack = []
        third = float('-inf')

        for x in reversed(nums):
            if x < third:
                return True

            while stack and stack[-1] < x:
                third = stack.pop()

            stack.append(x)

        return False

    """
    # Solution 4
    #
    # Prefix Minimum + Monotonic Stack
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution4(self, nums: List[int]) -> bool:
        n = len(nums)

        if n < 3:
            return False

        mins = [nums[0]] * n
        for j in range(1, n):
            mins[j] = min(mins[j - 1], nums[j])

        stack = []
        for j in range(n - 1, -1, -1):
            if nums[j] > mins[j]:
                while stack and stack[-1] <= mins[j]:
                    stack.pop()

                if stack and stack[-1] < nums[j]:
                    return True

            stack.append(nums[j])

        return False
