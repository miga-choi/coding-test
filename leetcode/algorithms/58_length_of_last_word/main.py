class LengthOfLastWord:
    def lengthOfLastWord(self, s: str) -> int:
        return len(list(filter(lambda s_: s_.strip() != "", s.split(" "))).pop(-1))


    # Best Solution
    # Best Solution 1:
    def bestSolution1(self, s: str) -> int:
        end = len(s) - 1
        while end > 0 and s[end] == " ":
            end -= 1
        beg = end
        while beg >= 0 and s[beg] != " ":
            beg -= 1
        return end - beg

    # Best Solution 2:
    def bestSolution2(self, s: str) -> int:
        return len(s.rstrip(" ").split(" ")[-1])

    # Best Solution 3:
    def bestSolution3(self, s: str) -> int:
        wordlist = s.split()
        if wordlist:
            return len(wordlist[-1])
        return 0
