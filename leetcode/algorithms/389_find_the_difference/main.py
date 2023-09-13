class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for c in s:
            t = t.replace(c, "", 1)
        return t


    # Best Solution
    def bestSolution(self, s: str, t: str) -> str:
        c = 0
        for cs in s:
            c ^= ord(cs)  # ord is ASCII value
        for ct in t:
            c ^= ord(ct)
        return chr(c)  # chr = convert ASCII into character
