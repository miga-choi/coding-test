import math

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:


def isBadVersion(version: int) -> bool:
    return True


class FirstBadVersion:
    """
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def firstBadVersion(self, n: int) -> int:
        left = 0
        right = n

        while left < right:
            mid = math.floor(left + (right - left) / 2)
            if isBadVersion(mid):
                right = mid
            else:
                left = mid + 1

        return left


    # Solution
    """
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution(self, n: int) -> int:
        left, right = 1, n

        while left < right:
            mid = left + (right - left) // 2

            if isBadVersion(mid):
                right = mid
            else:
                left = mid + 1

        return left
