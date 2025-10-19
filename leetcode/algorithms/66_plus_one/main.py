from typing import List


class PlusOne:
    """
    - Time Complexity: O(N)
    - Space Complexity: O(1)
    """
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits) - 1, -1, -1):
            digits[i] += 1

            if digits[i] < 10:
                return digits

            digits[i] -= 10

        return [1] + ([0] * len(digits))


    # Solution
    """
    Solution 1
    - Time Complexity: O(N)
    - Space Complexity: O(1)
    """
    def solution1(self, digits: List[int]) -> List[int]:
        n = len(digits)

        for i in range(n - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits

            digits[i] = 0

        return [1] + digits

    """
    Solution 1
    - Time Complexity: O(N)
    - Space Complexity: O(N)
    """
    def solution2(self, digits: List[int]) -> List[int]:
        s = "".join(map(str, digits))

        num_plus_one_str = str(int(s) + 1)

        return [int(digit) for digit in num_plus_one_str]
