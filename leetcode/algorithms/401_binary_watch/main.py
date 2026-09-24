from itertools import combinations
from typing import List


class BinaryWatch:
    """
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        result: List = []

        # Hour
        for h in range(12):
            # Minute
            for m in range(60):
                hCount = str(bin(h)[2:]).count("1")
                mCount = str(bin(m)[2:]).count("1")
                if hCount + mCount == turnedOn:
                    if m > 9:
                        result.append(f"{h}:{m}")
                    else:
                        result.append(f"{h}:0{m}")

        return result


    # Solution
    """
    # Solution 1
    # 
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution1(self, turnedOn: int) -> List[str]:
        result = []

        for h in range(12):
            for m in range(60):
                if bin(h).count('1') + bin(m).count('1') == turnedOn:
                    result.append(f"{h}:{m:02d}")

        return result

    """
    # Solution 2
    # 
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution2(self, turnedOn: int) -> List[str]:
        hour_bits = [8, 4, 2, 1]
        minute_bits = [32, 16, 8, 4, 2, 1]
        result = []

        for i in range(turnedOn + 1):
            j = turnedOn - i
            if i > 4 or j > 6:
                continue

            hours = [sum(c) for c in combinations(hour_bits, i)]
            minutes = [sum(c) for c in combinations(minute_bits, j)]

            for h in hours:
                if h > 11:
                    continue
                for m in minutes:
                    if m > 59:
                        continue
                    result.append(f"{h}:{m:02d}")

        return result

    """
    # Solution 3
    # 
    # Backtracking
    # 
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution3(self, turnedOn: int) -> List[str]:
        bits = [8, 4, 2, 1, 32, 16, 8, 4, 2, 1]
        result = []

        def backtrack(start: int, remain: int, hour: int, minute: int) -> None:
            if hour > 11 or minute > 59:
                return
            if remain == 0:
                result.append(f"{hour}:{minute:02d}")
                return
            for i in range(start, 10):
                if i < 4:
                    backtrack(i + 1, remain - 1, hour + bits[i], minute)
                else:
                    backtrack(i + 1, remain - 1, hour, minute + bits[i])

        backtrack(0, turnedOn, 0, 0)

        return result
