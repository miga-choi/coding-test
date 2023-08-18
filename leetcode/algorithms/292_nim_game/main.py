class Solution:
    def canWinNim(self, n: int) -> bool:
        if n % 4 == 0:
            return False
        return True


    # Best Solution
    def canWinNim(self, n: int) -> bool:
        if n <= 3:
            return True
        new_size = n + 1
        memo = [False] * (new_size)

        for i in range(4):
            memo[i] = True

        for i in range(4, new_size):
            for j in range(1, 4):
                if memo[i] == True:
                    break
                if memo[i - j] == True:
                    memo[i] = False
                else:
                    memo[i] = True

        return memo[n]
