from collections import Counter
from typing import List


class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return int(min(len(candyType) / 2, len(set(candyType))))


    # Best Solution
    def bestSolution(self, candyType: List[int]) -> int:
        return min(len(candyType) // 2, len(Counter(candyType)))
