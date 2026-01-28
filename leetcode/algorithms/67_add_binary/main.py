class AddBinary:
    """
    # BigInt
    #
    # Complexities:
    #   N - Length of `a`
    #   M - Length of `b`
    #   - Time Complexity: O(max(N, M))
    #   - Space Complexity: O(max(N, M))
    """
    def addBinary(self, a: str, b: str) -> str:
        return format(int(a, 2) + int(b, 2), "b")


    # Solution
    """
    # Solution 1
    #
    # Two Pointers & Carry
    #
    # Complexities:
    #   N - Length of `a`
    #   M - Length of `b`
    #   - Time Complexity: O(max(N, M))
    #   - Space Complexity: O(max(N, M))
    """
    def solution1(self, a: str, b: str) -> str:
        res = []
        carry = 0
        i, j = len(a) - 1, len(b) - 1

        while i >= 0 or j >= 0 or carry:
            total = carry

            if i >= 0:
                total += int(a[i])
                i -= 1

            if j >= 0:
                total += int(b[j])
                j -= 1

            res.append(str(total % 2))
            carry = total // 2

        return "".join(res[::-1])

    """
    # Solution 2
    #
    # Built-in function
    #
    # Complexities:
    #   N - Length of `a`
    #   M - Length of `b`
    #   - Time Complexity: O(max(N + M))
    #   - Space Complexity: O(max(N, M))
    """
    def solution2(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:]
