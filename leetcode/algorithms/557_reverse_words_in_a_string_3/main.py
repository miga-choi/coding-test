class Solution:
    def reverseWords(self, s: str) -> str:
        sArray = s.split(' ')
        result = ""
        for i in range(len(sArray)):
            sArray[i] = sArray[i][::-1]
        return " ".join(sArray)


    # Best Solution
    def bestSolution1(self, s: str) -> str:
        return ' '.join(s.split()[::-1])[::-1]

    def bestSolution2(self, s: str) -> str:
        return ' '.join(x[::-1] for x in s.split())
