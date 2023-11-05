from typing import List


class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        result = []
        sortedScore = sorted(score, reverse=True)

        for v in score:
            if sortedScore.index(v) == 0:
                result.append("Gold Medal")
            elif sortedScore.index(v) == 1:
                result.append("Silver Medal")
            elif sortedScore.index(v) == 2:
                result.append("Bronze Medal")
            else:
                result.append(f"{sortedScore.index(v) + 1}")

        return result


    # Best Solution
    def bestSolution(self, score: List[int]) -> List[str]:
        sort = sorted(score)[::-1]
        rank = ["Gold Medal", "Silver Medal", "Bronze Medal"] + map(
            str, range(4, len(score) + 1)
        )
        return map(dict(zip(sort, rank)).get, score)
