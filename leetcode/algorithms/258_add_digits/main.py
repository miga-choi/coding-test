class Solution:
    def addDigits(self, num: int) -> int:
        numString = str(num)
        while len(numString) > 1:
            num = 0
            for i in range(len(numString)):
                num += int(numString[i])
            numString = str(num)
        return num


    # Best Solution
    def bestSolution(self, num: int) -> int:
        while num > 9:
            num = num % 10 + num // 10
        return num
