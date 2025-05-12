class DetectCapital:
    def detectCapitalUse(self, word: str) -> bool:
        return (
            word == word.lower()
            or word == word.upper()
            or word == word[0].upper() + word[1:].lower()
        )


    # Solution
    # Solution 1
    def solution1(self, word: str) -> bool:
        return word.isupper() or word.islower() or word.istitle()

    # Solution 2
    def solution2(self, word: str) -> bool:
        c = 0

        for i in word:
            if i == i.upper():
                c += 1

        return c == len(word) or (c == 1 and word[0] == word[0].upper()) or c == 0
