class HappyNumber:
    """
    # Hash Map
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(logᴺ)
    """
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


    # Solution
    """
    # Solution 1
    #
    # Hash Set
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(logᴺ)
    """
    def solution1(self, n: int) -> bool:
        def get_next(number: int) -> int:
            total_sum = 0

            while number > 0:
                number, digit = divmod(number, 10)
                total_sum += digit ** 2

            return total_sum
        
        seen = set()
        
        while n != 1 and n not in seen:
            seen.add(n)
            n = get_next(n)
            
        return n == 1


    """
    # Solution 2
    #
    # Floyd's Cycle-Finding Algorithm
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution2(self, n: int) -> bool:
        def get_next(number: int) -> int:
            total_sum = 0

            while number > 0:
                number, digit = divmod(number, 10)
                total_sum += digit ** 2

            return total_sum
        
        slow = n
        fast = get_next(n)
        
        while fast != 1 and slow != fast:
            slow = get_next(slow)
            fast = get_next(get_next(fast))
            
        return fast == 1