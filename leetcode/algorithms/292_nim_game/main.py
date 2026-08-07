class NimGame:
    """
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def canWinNim(self, n: int) -> bool:
        if n % 4 == 0:
            return False
        return True


    # Solution
    """
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution(self, n: int) -> bool:
        return n % 4 != 0
