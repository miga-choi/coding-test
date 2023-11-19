class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        if len(s) < k:
            return s[::-1]

        result = ""
        for i in range(0, len(s), 2 * k):
            stringK = s[i : i + k]
            string2K = s[i + k : i + 2 * k]
            result += stringK[::-1] + string2K

        return result


    # Best Solution
    def bestSolution1(self, s: str, k: int) -> str:
        s = list(s)
        for i in xrange(0, len(s), 2 * k):
            s[i : i + k] = reversed(s[i : i + k])
        return "".join(s)


    def bestSolution2(self, s: str, k: int) -> str:
        # Divide s into an array of substrings length k
        s = [s[i : i + k] for i in range(0, len(s), k)]
        # Reverse every other substring, beginning with s[0]
        for i in range(0, len(s), 2):
            s[i] = s[i][::-1]
        # Join array of substrings into one string and return
        return "".join(s)
