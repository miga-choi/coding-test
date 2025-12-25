class validParentheses(object):
    """
    # LIFO (Last-In, First-Out): Stack
    #
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s:
            if c == "(":
                stack.append(")")
            elif c == "[":
                stack.append("]")
            elif c == "{":
                stack.append("}")
            else:
                if len(stack) == 0 or stack.pop() != c:
                    return False

        return len(stack) == 0


    # Solution
    """
    # LIFO (Last-In, First-Out): Stack
    #
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution(self, s: str) -> bool:
        bracket_map = {')': '(', '}': '{', ']': '['}
        stack = []

        for char in s:
            if char in bracket_map:
                top_element = stack.pop() if stack else '#'

                if bracket_map[char] != top_element:
                    return False
            else:
                stack.append(char)

        return not stack
