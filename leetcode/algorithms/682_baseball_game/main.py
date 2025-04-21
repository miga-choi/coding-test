from typing import List


class BaseballGame:
    def calPoints(self, operations: List[str]) -> int:
        scoreArray: List[int] = []

        for operation in operations:
            if operation == "+":
                scoreArray.append(scoreArray[len(scoreArray) - 2] + scoreArray[len(scoreArray) - 1])
            elif operation == "D":
                scoreArray.append(scoreArray[len(scoreArray) - 1] * 2)
            elif operation == "C":
                scoreArray.pop()
            else:
                scoreArray.append(int(operation))

        return sum(scoreArray)


    # Solution
    def solution(self, operations: List[str]) -> int:
        stack = []

        for operation in operations:
            if operation == '+':
                stack.append(stack[-1] + stack[-2])
            elif operation == 'C':
                stack.pop()
            elif operation == 'D':
                stack.append(2 * stack[-1])
            else:
                stack.append(int(operation))

        return sum(stack)
