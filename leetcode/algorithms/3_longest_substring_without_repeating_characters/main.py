from typing import List


class LongestSubstringWithoutRepeatingCharacters:
    """
    # Sliding Window (Using List)
    #
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
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
    """
    # Sliding Window (Using Dict)
    #
    # Complexities:
    #   N - Length of `s`
    #   M - Length of Available Characters in `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(Min(M, N))
    """
    def solution(self, s: str) -> int:
        char_index_map = {}

        max_length = 0
        start = 0

        for end in range(len(s)):
            current_char = s[end]

            if current_char in char_index_map and char_index_map[current_char] >= start:
                start = char_index_map[current_char] + 1

            char_index_map[current_char] = end

            max_length = max(max_length, end - start + 1)

        return max_length
