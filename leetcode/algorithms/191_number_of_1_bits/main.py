class NumberOf1Bits:
    def hammingWeight(self, n: int) -> int:
        n = bin(n).replace("0b", "")
        result = 0
        for c in n:
            if c == "1":
                result += 1
        return result


    # Solution
    # Solution 1: Using Inbuilt Counter
    def solution1(self, n):
        counter = collections.Counter(bin(n)[2:])
        return counter.get("1", 0)

    # Solution 2: Using Bit Manipulation
    def solution2(self, n):
        count = 0
        while n:
            if n & 1:
                count += 1
            n = n >> 1
        return count
