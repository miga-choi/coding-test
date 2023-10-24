import math
from typing import List


class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        w = math.floor(math.sqrt(area))
        while area % w != 0:
            w -= 1
        return [int(area / w), w]


    # Best Solution
    def bestSolution1(self, area: int) -> List[int]:
        for l in range(int(area**0.5), 0, -1):
            if area % l == 0:
                return [area // l, l]

    def bestSolution2(self, area: int) -> List[int]:
        mid = int(math.sqrt(area))
        while mid > 0:
            if area % mid == 0:
                return [int(area / mid), int(mid)]
            mid -= 1
