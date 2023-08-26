import math


class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n > 0 and math.log10(n) / math.log10(4) % 1 == 0:
            return True
        return False


    # Best Solution
    def isPowerOfFour(self, num: int) -> bool:
        return num > 0 and math.log(num, 4).is_integer()
