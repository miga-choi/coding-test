from typing import List


class LongestSubstringWithoutRepeatingCharacters:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charMap: List[int] = [-1] * 128
        left: int = 0
        maxLength: int = 0

        for right in range(0, len(s)):
            currentCharCode: int = ord(s[right])

            if charMap[currentCharCode] >= left:
                left = charMap[currentCharCode] + 1

            charMap[currentCharCode] = right

            maxLength = max(maxLength, right - left + 1)

        return maxLength


    # Solution
    # Solution 1: Set
    def solution1(self, s: str) -> int:
        n = len(s)
        maxLength = 0
        charSet = set()
        left = 0

        for right in range(n):
            if s[right] not in charSet:
                charSet.add(s[right])
                maxLength = max(maxLength, right - left + 1)
            else:
                while s[right] in charSet:
                    charSet.remove(s[left])
                    left += 1
                charSet.add(s[right])

        return maxLength

    # Solution 2: Map
    def solution2(self, s: str) -> int:
        n = len(s)
        maxLength = 0
        charMap = {}
        left = 0

        for right in range(n):
            if s[right] not in charMap or charMap[s[right]] < left:
                charMap[s[right]] = right
                maxLength = max(maxLength, right - left + 1)
            else:
                left = charMap[s[right]] + 1
                charMap[s[right]] = right

        return maxLength

    # Solution 3: Integer Array
    def solution3(self, s: str) -> int:
        n = len(s)
        maxLength = 0
        charIndex = [-1] * 128
        left = 0

        for right in range(n):
            if charIndex[ord(s[right])] >= left:
                left = charIndex[ord(s[right])] + 1
            charIndex[ord(s[right])] = right
            maxLength = max(maxLength, right - left + 1)

        return maxLength
