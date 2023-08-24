from typing import List


class Solution:
    def countBits(self, n: int) -> List[int]:
        result: List[int] = []

        for i in range(n + 1):
            sum: int = 0
            bits: str = f"{i:08b}"
            for bit in bits:
                sum += int(bit)
            result.append(sum)

        return result


    # Best Solution
    def countBits(self, num: int) -> List[int]:
        counter = [0]
        for i in range(1, num + 1):
            counter.append(counter[i >> 1] + i % 2)
        return counter
