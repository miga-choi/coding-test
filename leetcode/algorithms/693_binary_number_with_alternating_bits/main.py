class BinaryNumberWithAlternatingBits:
    def hasAlternatingBits(self, n: int) -> bool:
        prev: int = -1

        while n > 0:
            if n % 2 == prev:
                return False
            prev = n % 2
            n >>= 1

        return True


    # Solution
    # Solution 1
    def solution1(self, n: int) -> bool:
        if not n:
            return False

        num = n ^ (n >> 1)
        return not (num & (num + 1))

    # Solution 2
    def solution2(self, n: int) -> bool:
        s = bin(n)
        return '00' not in s and '11' not in s
