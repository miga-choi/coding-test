class ReverseBits:
    def reverseBits(self, n: int) -> int:
        n = bin(n).replace("0b", "")[::-1]

        while len(n) < 32:
            n += "0"

        return int(n, 2)


    # Solution
    def solution(self, n: int) -> int:
        res = 0
        for _ in range(32):
            res = (res << 1) + (n & 1)
            n >>= 1
        return res
