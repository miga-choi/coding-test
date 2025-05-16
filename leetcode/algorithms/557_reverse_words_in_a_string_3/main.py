class ReverseWordsInAStringIII:
    def reverseWords(self, s: str) -> str:
        sArray = s.split(' ')
        for i in range(len(sArray)):
            sArray[i] = sArray[i][::-1]
        return " ".join(sArray)


    # Solution
    # Solution 1
    def solution1(self, s: str) -> str:
        return ' '.join(s.split()[::-1])[::-1]

    # Solution 2
    def solution2(self, s: str) -> str:
        return ' '.join(x[::-1] for x in s.split())
