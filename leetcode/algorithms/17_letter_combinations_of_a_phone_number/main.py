from typing import List, Dict


class LetterCombinationsOfAPhoneNumber:
    """
    # Recursion: Backtracking (DFS)
    #
    # Complexities:
    #   - Time Complexity: O(4ᴺ)
    #   - Space Complexity: O(N)
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
    # Solution 1
    #
    # Recursion: Backtracking (DFS)
    #
    # Complexities:
    #   - Time Complexity: O(4ᴺ)
    #   - Space Complexity: O(N)
    """
    def solution1(self, digits: str) -> List[str]:
        phone_map = {
            "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
        }

        combinations = []

        def backtrack(index: int, path: str):
            if len(path) == len(digits):
                combinations.append(path)
                return

            current_digit = digits[index]
            possible_letters = phone_map[current_digit]

            for letter in possible_letters:
                backtrack(index + 1, path + letter)

        backtrack(0, "")

        return combinations

    """
    # Solution 2
    #
    # Iteration: BFS
    #
    # Complexities:
    #   - Time Complexity: O(4ᴺ)
    #   - Space Complexity: O(N)
    """
    def solution2(self, digits: str) -> List[str]:
        phone_map = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        result = [""]

        for digit in digits:
            temp = []

            for combination in result:
                for letter in phone_map[digit]:
                    temp.append(combination + letter)

            result = temp

        return result
