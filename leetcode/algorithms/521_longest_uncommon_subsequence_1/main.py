class LongestUncommonSubsequenceI:
    def findLUSlength(self, a: str, b: str) -> int:
        return -1 if a == b else max(len(a), len(b))


    # Solution
    def solution(self, a: str, b: str) -> int:
        return -1 if a == b else max(len(a), len(b))
