from typing import List


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g = sorted(g)
        s = sorted(s)
        gi = 0
        for sv in s:
            if gi >= len(g):
                break
            if sv >= g[gi]:
                gi += 1
        return gi


    # Best Solution
    def bestSolution(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()

        childi = 0
        cookiei = 0

        while cookiei < len(s) and childi < len(g):
            if s[cookiei] >= g[childi]:
                childi += 1
            cookiei += 1

        return childi
