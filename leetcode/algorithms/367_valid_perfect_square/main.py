import math


class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = 0
        while True:
            if i**2 == num:
                return True
            elif i**2 > num:
                return False
            else:
                i = i + 1


    # Best Solution
    def bestSolution(self, num: int) -> bool:
        return int(num**0.5) == num**0.5
