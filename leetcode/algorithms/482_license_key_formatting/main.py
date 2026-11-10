class LicenseKeyFormatting:
    """
    # Right-to-Left Chunking
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.replace("-", "").upper()
        result = ""

        for i in range(len(s) - 1, -1, -k):
            if i >= k:
                result = "-" + s[-k:] + result
            else:
                result = s[-k:] + result
            s = s[: i + 1 - k]

        return result


    # Solution
    """
    # Solution 1
    #
    # Reverse Traversal
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, s: str, k: int) -> str:
        result = []
        count = 0

        for c in reversed(s):
            if c == '-':
                continue
            if count == k:
                result.append('-')
                count = 0
            result.append(c.upper())
            count += 1

        return ''.join(reversed(result))

    """
    # Solution 2
    #
    # First Group Offset
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, s: str, k: int) -> str:
        cleaned = s.replace('-', '').upper()
        n = len(cleaned)

        if n == 0:
            return ""

        first = n % k or k
        groups = [cleaned[:first]]
        groups += [cleaned[i:i + k] for i in range(first, n, k)]

        return '-'.join(groups)

    """
    # Solution 3
    #
    # Reverse Chunking
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution3(self, s: str, k: int) -> str:
        rev = s.replace('-', '').upper()[::-1]
        chunks = [rev[i:i + k] for i in range(0, len(rev), k)]
        return '-'.join(chunks)[::-1]
