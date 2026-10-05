from typing import List


class FizzBuzz:
    """
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
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


    # Solution
    """
    # Solution 1
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, n: int) -> List[str]:
        result = []

        for i in range(1, n + 1):
            if i % 15 == 0:
                result.append("FizzBuzz")
            elif i % 3 == 0:
                result.append("Fizz")
            elif i % 5 == 0:
                result.append("Buzz")
            else:
                result.append(str(i))

        return result

    """
    # Solution 2
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, n: int) -> List[str]:
        result = []

        for i in range(1, n + 1):
            s = ""
            if i % 3 == 0:
                s += "Fizz"
            if i % 5 == 0:
                s += "Buzz"
            result.append(s or str(i))

        return result

    """
    # Solution 3
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution3(self, n: int) -> List[str]:
        rules = [(3, "Fizz"), (5, "Buzz")]

        return ["".join(word for d, word in rules if i % d == 0) or str(i) for i in range(1, n + 1)]

    """
    # Solution 4
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution4(self, n: int) -> List[str]:
        result = []
        fizz = buzz = 0

        for i in range(1, n + 1):
            fizz += 1
            buzz += 1
            s = ""
            if fizz == 3:
                s += "Fizz"
                fizz = 0
            if buzz == 5:
                s += "Buzz"
                buzz = 0
            result.append(s or str(i))

        return result
