class Solution:
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


    # Best Solution
    def bestSolution(self, s: str) -> str:
        s = list(s)
        left = 0
        right = len(s) - 1
        m = "aeiouAEIOU"
        while left < right:
            if s[left] in m and s[right] in m:
                s[left], s[right] = s[right], s[left]

                left += 1
                right -= 1

            elif s[left] not in m:
                left += 1

            elif s[right] not in m:
                right -= 1

        return "".join(s)
