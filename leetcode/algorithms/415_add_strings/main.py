from itertools import zip_longest


class AddStrings:
    """
    # Complexities:
    #   N - The Size of `num1`
    #   M - The Size of `num2`
    #   - Time Complexity: O(max(N, M))
    #   - Space Complexity: O(1)
    """
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


    # Solution
    """
    # Solution 1
    #
    # Two Pointers
    #
    # Complexities:
    #   N - The Size of `num1`
    #   M - The Size of `num2`
    #   - Time Complexity: O(max(N, M))
    #   - Space Complexity: O(1)
    """
    def solution1(self, num1: str, num2: str) -> str:
        i, j = len(num1) - 1, len(num2) - 1
        carry = 0
        result = []

        while i >= 0 or j >= 0 or carry:
            d1 = ord(num1[i]) - ord('0') if i >= 0 else 0
            d2 = ord(num2[j]) - ord('0') if j >= 0 else 0

            total = d1 + d2 + carry
            result.append(str(total % 10))
            carry = total // 10

            i -= 1
            j -= 1

        return ''.join(reversed(result))

    """
    # Solution 2
    #
    # itertools.zip_longest
    #
    # Complexities:
    #   N - The Size of `num1`
    #   M - The Size of `num2`
    #   - Time Complexity: O(max(N, M))
    #   - Space Complexity: O(1)
    """
    def solution2(self, num1: str, num2: str) -> str:
        carry = 0
        result = []

        for a, b in zip_longest(reversed(num1), reversed(num2), fillvalue='0'):
            total = ord(a) + ord(b) - 2 * ord('0') + carry
            result.append(str(total % 10))
            carry = total // 10

        if carry:
            result.append('1')

        return ''.join(reversed(result))
