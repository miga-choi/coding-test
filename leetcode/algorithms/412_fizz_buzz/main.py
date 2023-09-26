from typing import List


class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        result: List[str] = []

        for i in range(1, n + 1):
            if i % 3 == 0 and i % 5 == 0:
                result.append("FizzBuzz")
            elif i % 3 == 0:
                result.append("Fizz")
            elif i % 5 == 0:
                result.append("Buzz")
            else:
                result.append(f"{i}")

        return result


    # Best Solution
    def bestSolution(self, n: int) -> List[str]:
        return [
            "Fizz" * (not i % 3) + "Buzz" * (not i % 5) or str(i)
            for i in range(1, n + 1)
        ]
