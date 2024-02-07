class AddBinary:
    def addBinary(self, a: str, b: str) -> str:
        return format(int(a, 2) + int(b, 2), "b")


    # Best Solution
    # Best Solution 1:
    def bestSolution1(self, a: str, b: str) -> str:
        res = ""
        i, j, carry = len(a) - 1, len(b) - 1, 0
        while i >= 0 or j >= 0:
            sum = carry
            if i >= 0:
                sum += ord(a[i]) - ord(
                    "0"
                )  # ord is use to get value of ASCII character
            if j >= 0:
                sum += ord(b[j]) - ord("0")
            i, j = i - 1, j - 1
            carry = 1 if sum > 1 else 0
            res += str(sum % 2)

        if carry != 0:
            res += str(carry)
        return res[::-1]

    # Best Solution 2:
    def bestSolution2(self, a: str, b: str) -> str:
        s = []
        carry = 0
        i = len(a) - 1
        j = len(b) - 1

        while i >= 0 or j >= 0 or carry:
            if i >= 0:
                carry += int(a[i])
                i -= 1
            if j >= 0:
                carry += int(b[j])
                j -= 1
            s.append(str(carry % 2))
            carry //= 2

        return "".join(reversed(s))
