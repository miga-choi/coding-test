from math import floor
from typing import List


class SelfDividingNumbers:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        result: List[int] = []

        for i in range(left, right + 1):
            v: int = i

            while v > 0:
                if v % 10 == 0 or i % (v % 10) > 0:
                    break

                v = floor(v / 10)

            if v == 0:
                result.append(i)

        return result


    # Solution
    def solution(self, left: int, right: int) -> List[int]:
        return [
            x
            for x in range(left, right + 1)
            if all([int(i) != 0 and x % int(i) == 0 for i in str(x)])
        ]
