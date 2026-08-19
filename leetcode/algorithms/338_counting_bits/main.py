from typing import List


class CountBits:
    """
    # Time Complexity should <= O(N)
    #
    # Complexities:
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(N * logᴺ)
    """
    def countBits(self, n: int) -> List[int]:
        result: List[int] = []

        for i in range(n + 1):
            sum: int = 0
            bits: str = f"{i:08b}"
            for bit in bits:
                sum += int(bit)
            result.append(sum)

        return result


    # Solution
    """
    # Solution 1
    #
    # Time Complexity should <= O(N)
    #
    # Complexities:
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(N * logᴺ)
    """
    def solution1(self, n: int) -> List[int]:
        return [bin(i).count('1') for i in range(n + 1)]

    """
    # Solution 2
    #
    # DP (Dynamic programming)
    #
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, n: int) -> List[int]:
        dp = [0] * (n + 1)

        for i in range(1, n + 1):
            dp[i] = dp[i >> 1] + (i & 1)

        return dp

    """
    # Solution 3
    #
    # DP (Dynamic programming)
    #
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution3(self, n: int) -> List[int]:
        dp = [0] * (n + 1)

        for i in range(1, n + 1):
            dp[i] = dp[i & (i - 1)] + 1

        return dp

    """
    # Solution 4
    #
    # Built-in function
    #
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution4(self, n: int) -> List[int]:
        return [i.bit_count() for i in range(n + 1)]
