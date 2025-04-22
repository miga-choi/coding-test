class PowerOfTwo:
    def isPowerOfTwo(self, n: int) -> bool:
        m = 0

        while 2**m <= n:
            if 2**m == n:
                return True
            m = m + 1

        return False


    # Solution
    # Solution 1: O(1)
    def solution1(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0

    # Solution 2: O(n)
    def solution2(self, n: int) -> bool:
        return n > 0 and sum(list(map(int, bin(n)[2:]))) == 1
