class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for c in s:
            t = t.replace(c, "", 1)
        return t


    # Solution
    def solution(self, s: str, t: str) -> str:
        c = 0

        # ord is ASCII value
        for cs in s:
            c ^= ord(cs)

        # ord is ASCII value
        for ct in t:
            c ^= ord(ct)

        # chr = convert ASCII into character
        return chr(c)
