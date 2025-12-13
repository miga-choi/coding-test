class RomanToInteger:
    """
    # Map
    #
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def romanToInt(self, s: str) -> int:
        roman = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }

        s = (
            s.replace("CM", "DCCCC")
            .replace("CD", "CCCC")
            .replace("XC", "LXXXX")
            .replace("XL", "XXXX")
            .replace("IX", "VIIII")
            .replace("IV", "IIII")
        )

        result = 0

        for char in s:
            result += roman[char]

        return result


    # Solution
    """
    # Solution 1
    #
    # Left-to-Right Pass
    #
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, s: str) -> int:
        roman_map = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50,
            'C': 100, 'D': 500, 'M': 1000
        }
        
        total = 0
        n = len(s)
        
        for i in range(n):
            current_val = roman_map[s[i]]
            
            if i < n - 1 and current_val < roman_map[s[i+1]]:
                total -= current_val
            else:
                total += current_val
                
        return total

    """
    # Solution 2
    #
    # Right-to-Left Pass
    #
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, s: str) -> int:
        roman_map = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50,
            'C': 100, 'D': 500, 'M': 1000
        }
        
        total = 0
        prev_val = 0
        
        for char in reversed(s):
            curr_val = roman_map[char]
            
            if curr_val < prev_val:
                total -= curr_val
            else:
                total += curr_val
                
            prev_val = curr_val
            
        return total
