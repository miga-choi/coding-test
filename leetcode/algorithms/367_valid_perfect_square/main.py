class ValidPerfectSquare:
    def isPerfectSquare(self, num: int) -> bool:
        i = 0
        while True:
            if i**2 == num:
                return True
            elif i**2 > num:
                return False
            else:
                i = i + 1


    # Solution
    def solution(self, num: int) -> bool:
        return int(num**0.5) == num**0.5
