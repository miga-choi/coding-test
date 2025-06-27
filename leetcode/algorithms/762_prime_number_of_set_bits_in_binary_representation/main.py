class PrimeNumberOfSetBitsInBinaryRepresentation:
    def isPrime(self, n: int) -> bool:
        if n < 2:
            return False

        for i in range(2, n):
            if n % i == 0:
                return False

        return True

    def countPrimeSetBits(self, left: int, right: int) -> int:
        count: int = 0

        for i in range(left, right + 1):
            bits: int = 0
            n: int = i

            while n > 0:
                bits += n % 2
                n //= 2

            if self.isPrime(bits):
                count += 1

        return count


    # Solution
    def solution(self, left: int, right: int) -> int:
        return sum(665772 >> bin(i).count("1") & 1 for i in range(left, right + 1))
