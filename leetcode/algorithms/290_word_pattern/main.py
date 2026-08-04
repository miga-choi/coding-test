class WordPattern:
    """
    # Complexities:
    #   N - The size of `pattern`
    #   M - The size of `s`
    #   - Time Complexity: O(N * M)
    #   - Space Complexity: O(N + M)
    """
    def wordPattern(self, pattern: str, s: str) -> bool:
        sArray: list = s.split(" ")

        if len(sArray) != len(pattern):
            return False

        sMap: dict = {}

        for i in range(len(pattern)):
            if sMap.get(pattern[i]) == None:
                for v in list(sMap.values()):
                    if sArray[i] == v:
                        return False
                sMap.update({pattern[i]: sArray[i]})
            else:
                if sMap[pattern[i]] != sArray[i]:
                    return False

        return True


    # Solution
    """
    # Solution 1
    #
    # Two Hash Maps
    #
    # Complexities:
    #   L - The number of characters' length in `s`
    #   - Time Complexity: O(L)
    #   - Space Complexity: O(L)
    """
    def solution1(self, pattern: str, s: str) -> bool:
        words = s.split()
        
        if len(pattern) != len(words):
            return False
            
        char_to_word = {}
        word_to_char = {}
        
        for char, word in zip(pattern, words):
            if char in char_to_word:
                if char_to_word[char] != word:
                    return False
            else:
                char_to_word[char] = word
                
            if word in word_to_char:
                if word_to_char[word] != char:
                    return False
            else:
                word_to_char[word] = char
                
        return True

    """
    # Solution 2
    #
    # set & zip
    #
    # Complexities:
    #   L - The number of characters' length in `s`
    #   - Time Complexity: O(L)
    #   - Space Complexity: O(L)
    """
    def solution2(self, pattern: str, s: str) -> bool:
        words = s.split()
        
        if len(pattern) != len(words):
            return False
            
        return len(set(pattern)) == len(set(words)) == len(set(zip(pattern, words)))
