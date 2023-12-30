from typing import List


class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        for i in range(len(flowerbed)):
            if len(flowerbed) == 1:
                if flowerbed[i] == 0:
                    flowerbed[i] = 1
                    n -= 1
            else:
                if i == 0:
                    if flowerbed[i] == 0 and flowerbed[i + 1] == 0:
                        flowerbed[i] = 1
                        n -= 1
                elif i == len(flowerbed) - 1:
                    if flowerbed[i - 1] == 0 and flowerbed[i] == 0:
                        flowerbed[i] = 1
                        n -= 1
                else:
                    if (
                        flowerbed[i - 1] == 0
                        and flowerbed[i] == 0
                        and flowerbed[i + 1] == 0
                    ):
                        flowerbed[i] = 1
                        n -= 1
        return n <= 0


    # Best Solution
    # Best Solution 1:
    def bestSolution1(self, flowerbed: List[int], n: int) -> bool:
        if n == 0:
            return True
        for i in range(len(flowerbed)):
            if (
                flowerbed[i] == 0
                and (i == 0 or flowerbed[i - 1] == 0)
                and (i == len(flowerbed) - 1 or flowerbed[i + 1] == 0)
            ):
                flowerbed[i] = 1
                n -= 1
                if n == 0:
                    return True
        return False

    # Best Solution 2:
    def bestSolution2(self, flowerbed: List[int], n: int) -> bool:
        if n == 0:
            return True
        for i in range(len(flowerbed)):
            if (
                flowerbed[i] == 0
                and (i == 0 or flowerbed[i - 1] == 0)
                and (i == len(flowerbed) - 1 or flowerbed[i + 1] == 0)
            ):  # can place?
                n -= 1
                if n == 0:
                    return True
                flowerbed[i] = 1  # palce!
        return False

    # Best Solution 3:
    def bestSolution3(self, flowerbed: List[int], n: int) -> bool:
        zeros, ans = 1, 0  # Easier handling of prefixes, just initialize zeros to 1
        for f in flowerbed:
            if f == 0:
                zeros += 1
            else:
                ans += (zeros - 1) // 2
                zeros = 0
        return ans + zeros // 2 >= n  # Note that suffix zeros need not -1

    # Best Solution 4:
    def bestSolution4(self, flowerbed: List[int], n: int) -> bool:
        return (
            sum(
                (len(zeros) - 1) // 2
                for zeros in "".join(map(str, [0] + F + [0])).split("1")
            )
            >= n
        )
