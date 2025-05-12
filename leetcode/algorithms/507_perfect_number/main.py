import math


class PerfectNumber:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1:
            return False

        sum = 0
        for i in range(1, math.floor(num**0.5) + 1):
            print(i)
            if num % i == 0:
                sum += i + num / i

        return sum == num * 2


    # Solution
    # Solution 1: Only 5 perfect Number exist until 10^8
    def solution1(self, num: int) -> bool:
        return num in [6, 28, 496, 8128, 33550336]

    # Solution 2: Rooting Approach
    def solution2(self, num: int) -> bool:
        if num == 1:
            return False

        count = 1
        for i in range(2, int(num**0.5) + 1):
            if num % i == 0:
                count += i + num // i

        return num == count
