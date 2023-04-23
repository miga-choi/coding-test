class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        result = True
        if x < 0:
            result = False
        xStr = str(x)
        for i in range(0, len(xStr) - 1):
            if i == len(xStr) - 1 - i:
                break
            if xStr[i] != xStr[len(xStr) - 1 - i]:
                result = False
        return result
