from typing import List


class LongestCommonPrefix:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        length = len(strs[0])
        if len(strs) == 0:
            return ""
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


    # Best Solution:
    # Best Solution 1:
    def bestSolution1(self, strs: List[str]) -> str:
        ans = ""
        strs = sorted(strs)
        first = strs[0]
        last = strs[-1]
        for i in range(min(len(first), len(last))):
            if first[i] != last[i]:
                return ans
            ans += first[i]
        return ans

    # Best Solution 2:
    def bestSolution2(self, strs: List[str]) -> str:
        if not strs:
            return ""
        shortest = min(strs, key=len)
        for i, ch in enumerate(shortest):
            for other in strs:
                if other[i] != ch:
                    return shortest[:i]
        return shortest

    # Best Solution 3:
    def bestSolution3(self, strs: List[str]) -> str:
        if not strs:
            return ""
        # since list of string will be sorted and retrieved min max by alphebetic order
        s1 = min(strs)
        s2 = max(strs)

        for i, c in enumerate(s1):
            if c != s2[i]:
                return s1[:i]  # stop until hit the split index
        return s1

    # Best Solution 4:
    def bestSolution(self, strs: List[str]) -> str:
        l = list(zip(*strs))
        prefix = ""
        for i in l:
            if len(set(i)) == 1:
                prefix += i[0]
            else:
                break
        return prefix
