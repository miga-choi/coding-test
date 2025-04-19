class LengthOfLastWord:
    def lengthOfLastWord(self, s: str) -> int:
        return len(list(filter(lambda s_: s_.strip() != "", s.split(" "))).pop(-1))


    # Solution
    # Solution 1:
    def solution1(self, s: str) -> int:
        end = len(s) - 1
        while end > 0 and s[end] == " ":
            end -= 1
        beg = end
        while beg >= 0 and s[beg] != " ":
            beg -= 1
        return end - beg

    # Solution 2:
    def solution2(self, s: str) -> int:
        return len(s.rstrip(" ").split(" ")[-1])

    # Solution 3:
    def solution3(self, s: str) -> int:
        wordlist = s.split()
        if wordlist:
            return len(wordlist[-1])
        return 0
