# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:


class GuessNumberHigherOrLower:
    def guess(num: int) -> int:
        return 0

    def guessNumber(self, n: int) -> int:
        size = n / 2

        while self.guess(n) != 0:
            if self.guess(n) > 0:
                n += size
            else:
                n -= size
            size /= 2

        return int(n)


    # Solution
    def solution(self, n: int) -> int:
        lowerBound, upperBound = 1, n

        # Binary division faster than (lowerBound + upperBound) //2
        myGuess = (lowerBound + upperBound) >> 1

        # walrus operator ':=' - assigns value of the function to the variable 'res'
        # and then compare res with 0
        while (res := self.guess(myGuess)) != 0:
            if res == 1:
                lowerBound = myGuess + 1
            else:
                upperBound = myGuess - 1
            myGuess = (lowerBound + upperBound) >> 1

        return myGuess
