class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        result = ""
        length = len(num1)
        if len(num2) > length:
            length = len(num2)

        for i in range(length):
            if len(num1) < length:
                num1 = "0" + num1
            if len(num2) < length:
                num2 = "0" + num2

        up = 0
        for i in range(length - 1, -1, -1):
            num = int(num1[i]) + int(num2[i]) + up
            up = 0

            if num > 9:
                num -= 10
                up += 1

            result = str(num) + result

            if i == 0 and up > 0:
                result = str(up) + result

        return result


    # Best Solution
    def bestSolution(self, num1: str, num2: str) -> str:
        num1, num2 = list(num1), list(num2)
        carry, res = 0, []
        while len(num2) > 0 or len(num1) > 0:
            n1 = ord(num1.pop()) - ord("0") if len(num1) > 0 else 0
            n2 = ord(num2.pop()) - ord("0") if len(num2) > 0 else 0

            temp = n1 + n2 + carry
            res.append(temp % 10)
            carry = temp // 10
        if carry:
            res.append(carry)
        return "".join([str(i) for i in res])[::-1]
