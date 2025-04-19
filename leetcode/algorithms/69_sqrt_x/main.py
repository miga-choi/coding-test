class SqrtX:
    def mySqrt(self, x: int) -> int:
        for i in range(x + 1):
            if i * i <= x and (i + 1) * (i + 1) > x:
                return i


    # Solution
    # Solution 1:
    def solution1(self, x: int) -> int:
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

    # Solution 2:
    def solution2(self, x: int) -> int:
        l, r = 0, x
        while l <= r:
            mid = l + (r - l) // 2
            if mid * mid <= x < (mid + 1) * (mid + 1):
                return mid
            elif x < mid * mid:
                r = mid - 1
            else:
                l = mid + 1
