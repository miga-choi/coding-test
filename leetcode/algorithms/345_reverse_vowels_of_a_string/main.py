class ReverseVowelsOfAString:
    """
    # Two Pointers
    #
    # Complexities:
    #   N - The size of `s`
    #   - Time Complexities: O(N)
    #   - Space Complexities: O(N)
    """
    def reverseVowels(self, s: str) -> str:
        result = ""
        vowels = ["A", "E", "I", "O", "U", "a", "e", "i", "o", "u"]
        vowelStack = []

        for c in s:
            if c in vowels:
                vowelStack.append(c)

        for i in range(len(s)):
            if s[i] in vowels:
                result += vowelStack.pop()
            else:
                result += s[i]

        return result


    # Solution
    """
    # Solution 1
    #
    # Two Pointers
    #
    # Complexities:
    #   N - The size of `s`
    #   - Time Complexities: O(N)
    #   - Space Complexities: O(N)
    """
    def solution1(self, s: str) -> str:
        vowels = set('aeiouAEIOU')
        chars = list(s)
        left, right = 0, len(chars) - 1

        while left < right:
            while left < right and chars[left] not in vowels:
                left += 1
            while left < right and chars[right] not in vowels:
                right -= 1

            chars[left], chars[right] = chars[right], chars[left]
            left += 1
            right -= 1

        return ''.join(chars)

    """
    # Solution 2
    #
    # Complexities:
    #   N - The size of `s`
    #   - Time Complexities: O(N)
    #   - Space Complexities: O(N)
    """
    def solution2(self, s: str) -> str:
        vowels = set('aeiouAEIOU')
        found = [c for c in s if c in vowels]
        chars = list(s)

        for i, c in enumerate(chars):
            if c in vowels:
                chars[i] = found.pop()

        return ''.join(chars)
