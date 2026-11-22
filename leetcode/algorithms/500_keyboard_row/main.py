import re
from typing import List


class KeyboardRow:
    """
    # Row Lookup Table + First-Letter Row Check
    #
    # Complexities:
    #   i - Length of iᵗʰ Word in `words`
    #   - Time Complexity: O(Σ lenᵢ²)
    #   - Space Complexity: O(1)
    """
    def findWords(self, words: List[str]) -> List[str]:
        result = []

        for word in words:
            row = 0
            if len(word) == 1:
                result.append(word)
            else:
                wordLower = word.lower()
                isTrue = True
                for c in wordLower:
                    if row == 0:
                        if "qwertyuiop".count(c) > 0:
                            row = 1
                        elif "asdfghjkl".count(c) > 0:
                            row = 2
                        elif "zxcvbnm".count(c) > 0:
                            row = 3
                    else:
                        if row == 1 and "qwertyuiop".count(c) == 0:
                            isTrue = False
                            break
                        elif row == 2 and "asdfghjkl".count(c) == 0:
                            isTrue = False
                            break
                        elif row == 3 and "zxcvbnm".count(c) == 0:
                            isTrue = False
                            break
                if isTrue:
                    result.append(word)

        return result


    # Solution
    """
    # Solution 1
    #
    # Set Subset Check
    #
    # Complexities:
    #   n - Sum of The Number of Characters in `words`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(1)
    """
    def solution1(self, words: List[str]) -> List[str]:
        rows = [set("qwertyuiop"), set("asdfghjkl"), set("zxcvbnm")]

        return [w for w in words if any(set(w.lower()) <= row for row in rows)]

    """
    # Solution 2
    #
    # Character-to-Row Mapping
    #
    # Complexities:
    #   n - Sum of The Number of Characters in `words`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(1)
    """
    def solution2(self, words: List[str]) -> List[str]:
        rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        row_of = {c: i for i, row in enumerate(rows) for c in row}

        result = []

        for w in words:
            lw = w.lower()
            target = row_of[lw[0]]

            if all(row_of[c] == target for c in lw):
                result.append(w)

        return result

    """
    # Solution 3
    #
    # Regular Expression Matching
    #
    # Complexities:
    #   n - Sum of The Number of Characters in `words`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(1)
    """
    def solution3(self, words: List[str]) -> List[str]:
        pattern = re.compile(r"[qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*", re.IGNORECASE)
        return [w for w in words if pattern.fullmatch(w)]
