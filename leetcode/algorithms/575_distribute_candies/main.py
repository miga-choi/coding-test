from collections import Counter
from typing import List


class DistributeCandies:
    def distributeCandies(self, candyType: List[int]) -> int:
        return int(min(len(candyType) / 2, len(set(candyType))))


    # Solution
    def solution(self, candyType: List[int]) -> int:
        return min(len(candyType) // 2, len(Counter(candyType)))
