from typing import List


class TeemoAttacking:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        result = 0

        for i in range(1, len(timeSeries)):
            if timeSeries[i] - timeSeries[i - 1] >= duration:
                result += duration
            else:
                result += timeSeries[i] - timeSeries[i - 1]

        result += duration

        return result


    # Solution
    def solution(self, timeSeries: List[int], duration: int) -> int:
        ans = duration * len(timeSeries)

        for i in range(1, len(timeSeries)):
            ans -= max(0, duration - (timeSeries[i] - timeSeries[i - 1]))

        return ans
