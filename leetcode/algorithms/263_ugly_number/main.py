class UglyNumber:
    def isUgly(self, n: int) -> bool:
        if n < 1:
            return False

        while n > 1:
            if n % 5 == 0:
                n /= 5
            elif n % 3 == 0:
                n /= 3
            elif n % 2 == 0:
                n /= 2
            else:
                return False

        return True


    # Solution
    def solution(self, num: int) -> bool:
        if num == 0:
            return False
        while num % 5 == 0:
            num /= 5
        while num % 3 == 0:
            num /= 3
        while num % 2 == 0:
            num /= 2
        return num == 1
