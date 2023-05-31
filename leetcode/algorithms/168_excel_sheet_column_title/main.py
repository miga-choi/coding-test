class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        alphabet = [
            "A",
            "B",
            "C",
            "D",
            "E",
            "F",
            "G",
            "H",
            "I",
            "J",
            "K",
            "L",
            "M",
            "N",
            "O",
            "P",
            "Q",
            "R",
            "S",
            "T",
            "U",
            "V",
            "W",
            "X",
            "Y",
            "Z",
        ]

        result = ""

        while columnNumber > 0:
            result = alphabet[(columnNumber - 1) % 26] + result
            columnNumber = (columnNumber - 1) // 26

        return result

    # Best Solution
    def bestSolution1(self, columnNumber):
        # Create an empty string for storing the characters...
        output = ""
        # Run a while loop while columnNumber is positive...
        while columnNumber > 0:
            # Subtract 1 from columnNumber and get current character by doing modulo of columnNumber by 26...
            output = chr(ord("A") + (columnNumber - 1) % 26) + output
            # Divide columnNumber by 26...
            columnNumber = (columnNumber - 1) // 26
        # Return the output string.
        return output

    def bestSolution2(self, columnNumber):
        return "" if num == 0 else self.convertToTitle((num - 1) / 26) + chr((num - 1) % 26 + ord("A"))
