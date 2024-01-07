class PalindromeNumber:
    def isPalindrome(self, x: int) -> bool:
        result = True
        if x < 0:
            result = False
        xStr = str(x)
        for i in range(0, len(xStr) - 1):
            if i == len(xStr) - 1 - i:
                break
            if xStr[i] != xStr[len(xStr) - 1 - i]:
                result = False
        return result


    # Best Solution
    # Best Solution 1: Reversing the Entire Number
    def bestSolution1(self, x: int) -> bool:
        if x < 0:
            return False

        reversed_num = 0
        temp = x

        while temp != 0:
            digit = temp % 10
            reversed_num = reversed_num * 10 + digit
            temp //= 10

        return reversed_num == x

    # Best Solution 2: Reversing Half of the Number
    def bestSolution2(self, x: int) -> bool:
        if x < 0 or (x != 0 and x % 10 == 0):
            return False

        reversed_num = 0

        while x > reversed_num:
            reversed_num = reversed_num * 10 + x % 10
            x //= 10

        return x == reversed_num or x == reversed_num // 10
