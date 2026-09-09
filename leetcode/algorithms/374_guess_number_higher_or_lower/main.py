from bisect import bisect_left

class GuessNumberHigherOrLower:
    # The guess API is already defined for you.
    # @param num, your guess
    # @return -1 if num is higher than the picked number
    #          1 if num is lower than the picked number
    #          otherwise return 0
    # def guess(num: int) -> int:
    def guess(num: int) -> int:
        return 0

    """
    # Binary Search
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def guessNumber(self, n: int) -> int:
        size = n / 2

        while self.guess(n) != 0:
            if self.guess(n) > 0:
                n += size
            else:
                n -= size
            size /= 2

        return int(n)


    # Solution
    """
    # Solution 1
    # 
    # Binary Search
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution1(self, n: int) -> int:
        left, right = 1, n

        while left <= right:
            mid = left + (right - left) // 2
            result = guess(mid)

            if result == 0:
                return mid
            elif result == -1:
                right = mid - 1
            else:
                left = mid + 1

        return -1

    """
    # Solution 2
    # 
    # bisect.bisect_left
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution2(self, n: int) -> int:
        return bisect_left(range(1, n + 1), 0, key=lambda x: -self.guess(x))
