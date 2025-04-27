import math


class PowerOfThree:
    def isPowerOfThree(self, n: int) -> bool:
        if n > 0 and math.log10(n) / math.log10(3) % 1 == 0:
            return True
        return False


    # Solution
    def solution(self, n: int) -> bool:
        # Since error exist, can't use float.is_integer() to check
        # So I choose to check it back
        if n <= 0:
            return False
        res = round(math.log(n, 3))
        return 3**res == n
