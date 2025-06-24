from typing import Counter, List


class ShortestCompletingWord:
    def isCompleting(self, plateFreq: List[int], word: str) -> bool:
        wordFreq: List[int] = [0] * 26

        for char in word:
            wordFreq[ord(char) - 97] += 1

        for i in range(0, 26):
            if wordFreq[i] < plateFreq[i]:
                return False

        return True

    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        plateFreq: List[int] = [0] * 26

        licensePlate = licensePlate.lower()

        for char in licensePlate:
            if char.isalpha():
                plateFreq[ord(char) - 97] += 1

        shortestWord: str = ""
        minLength: int = 15

        for word in words:
            currentLength: int = len(word)

            if currentLength >= minLength:
                continue

            if self.isCompleting(plateFreq, word):
                minLength = currentLength
                shortestWord = word

        return shortestWord


    # Solution
    # Solution 1
    primes: List[int] = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                         47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]

    def getCharProduct(self, plate: str) -> int:
        product: int = 1

        for c in plate:
            index: int = ord(c) - 97
            if 0 <= index and index <= 25:
                product *= self.primes[index]

        return product

    def solution1(self, licensePlate: str, words: List[str]) -> str:
        charProduct: int = self.getCharProduct(licensePlate.lower())
        shortest: str = "aaaaaaaaaaaaaaaaaaaa"  # 16 a's

        for word in words:
            if (
                len(word) < len(shortest)
                and self.getCharProduct(word) % charProduct == 0
            ):
                shortest = word

        return shortest

    # Solution 2
    def solution2(self, licensePlate: str, words: List[str]) -> str:
        pc = Counter(filter(lambda x: x.isalpha(), licensePlate.lower()))
        return min([w for w in words if Counter(w) & pc == pc], key=len)
