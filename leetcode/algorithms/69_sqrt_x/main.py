class SqrtX:
    """
    # Complexities:
    #   N - Value of `x`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def mySqrt(self, x: int) -> int:
        for i in range(x + 1):
            if i * i <= x and (i + 1) * (i + 1) > x:
                return i


    # Solution
    """
    # Solution 1
    #
    # Binary Search
    #
    # Complexities:
    #   N - Value of `x`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution1(self, x: int) -> int:
        if x < 2:
            return x
        
        left, right = 1, x
        
        while left <= right:
            mid = (left + right) // 2
            square = mid * mid
            
            if square == x:
                return mid
            elif square < x:
                left = mid + 1
            else:
                right = mid - 1
        
        return right

    """
    # Solution 2
    #
    # Newton-Raphson Method
    #
    # Complexities:
    #   N - Value of `x`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution2(self, x: int) -> int:
        if x < 2:
            return x
        
        r = x
        
        while r * r > x:
            r = (r + x // r) // 2
            
        return r
