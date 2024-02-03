from typing import List


class PlusOne:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits) - 1, -1, -1):
            digits[i] = digits[i] + 1
            if digits[i] > 9:
                digits[i] = 0
            else:
                return digits
        digits.insert(0, 1)
        return digits


    # Best Solution
    # Best Solution 1:
    def bestSolution1(self, digits: List[int]) -> List[int]:
        num = 0
        for i in range(len(digits)):
            num += digits[i] * pow(10, (len(digits) - 1 - i))
        return [int(i) for i in str(num + 1)]

    # Best Solution 2:
    def bestSolution2(self, digits: List[int]) -> List[int]:
        if digits[-1] < 9:
            digits[-1] += 1
            return digits
        elif len(digits) == 1 and digits[0] == 9:
            return [1, 0]
        else:
            digits[-1] = 0
            digits[0:-1] = self.plusOne(digits[0:-1])
            return digits

    # Best Solution 3: Array
    def bestSolution3(self, digits: List[int]) -> List[int]:
        for i in range(len(digits) - 1, -1, -1):
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] = digits[i] + 1
                return digits
        return [1] + digits

    # Best Solution 4: Convert list -> Number :: -> Addition +1 :: -> Number -> List
    def bestSolution4(self, digits: List[int]) -> List[int]:
        # List -> Number
        n = 0
        for ele in digits:
            n = (n * 10) + ele

        n = n + 1

        # Number -> List
        digits = []
        while n > 0:
            digits.insert(0, n % 10)
            n //= 10
        return digits
