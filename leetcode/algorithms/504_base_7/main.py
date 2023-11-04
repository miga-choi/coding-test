class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"

        numString = ""
        ifNegative = False

        if num < 0:
            num *= -1
            ifNegative = True

        while num > 0:
            num, remainder = divmod(num, 7)
            numString = str(remainder) + numString

        if ifNegative:
            numString = "-" + numString

        return numString


    # Best Solution
    def bestSolution1(self, num: int) -> str:
        if num < 0:
            return "-" + self.convertToBase7(-num)
        if num < 7:
            return str(num)
        return self.bestSolution1(num // 7) + str(num % 7)

    def bestSolution2(self, num: int) -> str:
        if not num:
            return "0"

        sign = num < 0
        num = abs(num)

        stack = []
        while num:
            stack.append(str(num % 7))
            num = num // 7

        return "-" * sign + "".join(stack[::-1])
