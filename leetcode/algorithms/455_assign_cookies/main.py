from typing import List


class AssignCookies:
    """
    # Sorting + Greedy
    # 
    # Complexities:
    #   N - The Size of `g`
    #   M - The Size of `s`
    #   - Time Complexity: O(N * logᴺ + M * logᴹ)
    #   - Space Complexity: O(1)
    """
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g = sorted(g)
        s = sorted(s)

        gi = 0
        for sv in s:
            if gi >= len(g):
                break
            if sv >= g[gi]:
                gi += 1

        return gi


    # Solution
    """
    # Solution 1
    #
    # Sorting + Greedy
    # 
    # Complexities:
    #   N - The Size of `g`
    #   M - The Size of `s`
    #   - Time Complexity: O(N * logᴺ + M * logᴹ)
    #   - Space Complexity: O(1)
    """
    def solution1(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        child = cookie = 0

        while child < len(g) and cookie < len(s):
            if s[cookie] >= g[child]:
                child += 1
            cookie += 1

        return child

    """
    # Solution 2
    #
    # Sorting + Greedy
    # 
    # Complexities:
    #   N - The Size of `g`
    #   M - The Size of `s`
    #   - Time Complexity: O(N * logᴺ + M * logᴹ)
    #   - Space Complexity: O(1)
    """
    def solution2(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        cookie = len(s) - 1
        count = 0

        for child in range(len(g) - 1, -1, -1):
            if cookie >= 0 and s[cookie] >= g[child]:
                count += 1
                cookie -= 1

        return count
