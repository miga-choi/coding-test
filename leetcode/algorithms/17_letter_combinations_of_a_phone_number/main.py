from typing import List, Dict


class LetterCombinationsOfAPhoneNumber:
    """
    # Recursion: Backtracking (DFS)
    # - Time Complexity: O(4ᴺ)
    # - Space Complexity: O(N)
    """
    letters_map: Dict[str, str] = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }

    def backtracking(self, digits: str, index: int) -> None:
        if index == len(digits):
            self.result.append(self.row)
            return

        letters: str = self.letters_map[digits[index]]
        for letter in letters:
            self.row += letter
            self.backtracking(digits, index + 1)
            self.row = self.row[:-1]

    def letterCombinations(self, digits: str) -> List[str]:
        self.result: List[str] = []
        self.row: str = ""

        self.backtracking(digits, 0)

        return self.result


    # Solution
    """
    # Recursion: Backtracking (DFS)
    # - Time Complexity: O(4ᴺ)
    # - Space Complexity: O(N)
    """
    def solution(self, digits: str) -> List[str]:
        keypad = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        result = []

        def backtrack(index: int, path: List[str]):
            if index == len(digits):
                result.append("".join(path))
                return

            current_digit = digits[index]
            letters = keypad[current_digit]

            for letter in letters:
                path.append(letter)
                backtrack(index + 1, path)
                path.pop()

        backtrack(0, [])

        return result
