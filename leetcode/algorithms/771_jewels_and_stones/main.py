from typing import List


class JewelsAndStones:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        numsArray: List[int] = [0] * 128
        for jewel in jewels:
            numsArray[ord(jewel)] = 1

        count: int = 0
        for stone in stones:
            count += numsArray[ord(stone)]

        return count


    # Solution
    # Solution 1
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(map(jewels.count, stones))

    # Solution 2
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(map(stones.count, jewels))

    # Solution 3
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(stone in jewels for stone in stones)

    # Solution 4: set
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        jewelsSet = set(jewels)
        return sum(stone in jewelsSet for stone in stones)
