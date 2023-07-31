class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sMap: dict = {}

        for c_ in s:
            if sMap.get(c_) == None:
                sMap[c_] = 1
            else:
                sMap[c_] = sMap[c_] + 1

        for c_ in t:
            if sMap.get(c_) != None and sMap.get(c_) > 0:
                sMap[c_] = sMap[c_] - 1
            else:
                return False

        for v_ in sMap.values():
            if v_ > 0:
                return False

        return True


    # Best Solution
    def bestSolution(self, s: str, t: str) -> bool:
        sorted_s = sorted(s)
        sorted_t = sorted(t)
        return sorted_s == sorted_t
