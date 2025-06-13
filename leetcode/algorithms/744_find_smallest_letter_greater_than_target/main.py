from typing import List


class FindSmallestLetterGreaterThanTarget:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if letters[len(letters) - 1] <= target:
            return letters[0]

        for i in range(len(letters)):
            if letters[i] > target:
                return letters[i]

        return letters[0]


    # Solution
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        # if the number is out of bound
        if target >= letters[-1] or target < letters[0]:
            return letters[0]

        low = 0
        high = len(letters) - 1

        while low <= high:
            mid = (high + low) // 2

            # in binary search this would be only greater than
            if target >= letters[mid]:
                low = mid + 1

            if target < letters[mid]:
                high = mid - 1

        return letters[low]
