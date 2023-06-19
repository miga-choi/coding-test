class Solution:
    def isHappy(self, n: int) -> bool:
        if n <= 1:
            return True
        numDict: dict = {}
        while n > 1:
            nString = str(n)
            if numDict.get(nString) is True:
                return False
            numDict[nString] = True
            n = 0
            for c in nString:
                n += int(c) ** 2
            if n is 1:
                return True
        return False


# Best Solution
# best solution 1
def bestSolution1(self, n: int) -> bool:
    # 20 -> 4 -> 16 -> 37 -> 58 -> 89 -> 145 > 42 -> 20
    slow = self.squared(n)
    fast = self.squared(self.squared(n))

    while slow != fast and fast != 1:
        slow = self.squared(slow)
        fast = self.squared(self.squared(fast))

    return fast == 1


def squared(self, n):
    result = 0
    while n > 0:
        last = n % 10
        result += last * last
        n = n // 10
    return result


# best solution 2
def bestSolution2(self, n):
    mem = set()
    while n != 1:
        n = sum([int(i) ** 2 for i in str(n)])
        if n in mem:
            return False
        else:
            mem.add(n)
    else:
        return True
