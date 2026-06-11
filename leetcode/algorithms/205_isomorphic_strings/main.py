class IsomorphicStrings:
    """
    # Complexities:
    #   N - Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        sMap: dict = {}
        tMap: dict = {}

        for i in range(len(s)):
            if sMap.get(s[i]) != tMap.get(t[i]):
                return False
            sMap.update({s[i]: i + 1})
            tMap.update({t[i]: i + 1})

        return True


    # Solution
    """
    # Solution 1
    #
    # Complexities:
    #   N - Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        map_s = {}
        map_t = {}
        
        for char_s, char_t in zip(s, t):
            if char_s in map_s:
                if map_s[char_s] != char_t:
                    return False
            else:
                map_s[char_s] = char_t
                
            if char_t in map_t:
                if map_t[char_t] != char_s:
                    return False
            else:
                map_t[char_t] = char_s
                
        return True

    """
    # Solution 2
    #
    # Complexities:
    #   N - Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, s: str, t: str) -> bool:
        return len(set(s)) == len(set(t)) == len(set(zip(s, t)))

