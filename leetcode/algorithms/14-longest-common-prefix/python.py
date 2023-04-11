class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        result = ''
        length = len(strs[0])
        if len(strs) == 0:
            return ''
        if len(strs) == 1:
            return strs[0]
        for strc in strs:
            if len(strc) == 0:
                return ''
            if length > len(strc):
                length = len(strc)
        for i in range(0, length):
            same = True
            for j in range(0, len(strs)):
                if j >= len(strs) - 1:
                    continue
                if strs[j][i] != strs[j+1][i]:
                    same = False
            if same:
                result += strs[j][i]
            else:
                break
        return result
