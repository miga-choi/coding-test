class LengthOfLastWord:
    """
    # Built-in function
    # 
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def lengthOfLastWord(self, s: str) -> int:
        return len(list(filter(lambda s_: s_.strip() != "", s.split(" "))).pop(-1))


    # Solution
    """
    # Solution 1
    # 
    # Reverse Traversal
    # 
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, s: str) -> int:
        length = 0
        i = len(s) - 1
        
        while i >= 0 and s[i] == ' ':
            i -= 1
            
        while i >= 0 and s[i] != ' ':
            length += 1
            i -= 1
            
        return length

    """
    # Solution 2
    # 
    # Built-in function
    # 
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, s: str) -> int:
        words = s.split()
        
        return len(words[-1])
