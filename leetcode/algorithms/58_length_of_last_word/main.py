class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(list(filter(lambda s_: s_.strip() != "", s.split(" "))).pop(-1))

    # Best Solution
    def bestSolution(self, s):
        wordlist = s.split()
        if wordlist:
            return len(wordlist[-1])
        return 0
