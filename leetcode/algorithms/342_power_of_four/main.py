import math


class PowerOfFour:
    def isPowerOfFour(self, n: int) -> bool:
        if n > 0 and math.log10(n) / math.log10(4) % 1 == 0:
            return True
        return False


    # Solution
    def solution(self, num: int) -> bool:
        return num > 0 and math.log(num, 4).is_integer()
