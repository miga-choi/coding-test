class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        sMap: dict = {}
        tMap: dict = {}

        for i in range(len(s)):
            if sMap.get(s[i]) != tMap.get(t[i]):
                return False
            sMap.update({s[i]: i + 1})
            tMap.update({t[i]: i + 1})

        return True

    
    # Best Solution
    def bestSolution(self, s: str, t: str) -> bool:
        map1 = []
        map2 = []
        for idx in s:
            map1.append(s.index(idx))
        for idx in t:
            map2.append(t.index(idx))
        if map1 == map2:
            return True
        return False
