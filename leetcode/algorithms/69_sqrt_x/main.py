class Solution:
    def mySqrt(self, x: int) -> int:
        for i in range(x + 1):
            if i * i <= x and (i + 1) * (i + 1) > x:
                return i

    # Best Solution
    def bestSolution(self, x: int) -> int:
        if x == 0:
            return 0
        first, last = 1, x
        while first <= last:
            mid = first + (last - first) // 2
            if mid == x // mid:
                return mid
            elif mid > x // mid:
                last = mid - 1
            else:
                first = mid + 1
        return last
