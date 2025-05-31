from typing import List


class OneBitAndTwoBitCharacters:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i: int = 0

        while i < len(bits) - 1:
            if bits[i] == 1:
                i += 2
            else:
                i += 1

        return i == len(bits) - 1


    # Solution
    # Solution 1: Increment Pointer
    def solution1(self, bits: List[int]) -> bool:
        i: int = 0

        while i < len(bits) - 1:
            i += bits[i] + 1

        return i == len(bits) - 1

    # Solution 2: Greedy
    def solution2(self, bits: List[int]) -> bool:
        parity: int = bits.pop()

        while bits and bits.pop():
            parity ^= 1

        return parity == 0
