from typing import List


class LongestCommonPrefix:
    """
    # Complexities:
    #   S = N * L
    #   N - `strsSize`
    #   L - Length of Shortest `str` in `strs
    #   - Time Complexity: O(S)
    #   - Space Complexity: O(1)
    """
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        length = len(strs[0])

        if len(strs) == 1:
            return strs[0]

        for strc in strs:
            if len(strc) == 0:
                return ""
            if length > len(strc):
                length = len(strc)

        for i in range(0, length):
            same = True

            for j in range(0, len(strs)):
                if j >= len(strs) - 1:
                    continue
                if strs[j][i] != strs[j + 1][i]:
                    same = False

            if same:
                result += strs[j][i]
            else:
                break

        return result


    # Solution
    """
    # Solution 1
    #
    # Vertical Scanning with zip
    #
    # Complexities:
    #   S - Quantity of characters in `strs`
    #   - Time Complexity: O(S)
    #   - Space Complexity: O(1)
    """
    def solution1(self, strs: List[str]) -> str:
        prefix = ""
        
        for chars in zip(*strs):
            if len(set(chars)) == 1:
                prefix += chars[0]
            else:
                break
                
        return prefix

    """
    # Solution 2
    # 
    # Sorting
    #
    # Complexities:
    #   N - Length of `strs`
    #   L - Length of Longest `str` in `strs`
    #   - Time Complexity: O(N * L * logᴺ)
    #   - Space Complexity: O(logᴺ)
    """
    def solution2(self, strs: List[str]) -> str:
        strs.sort()
        
        first = strs[0]
        last = strs[-1]
        
        i = 0

        while i < len(first) and i < len(last):
            if first[i] != last[i]:
                break

            i += 1
            
        return first[:i]