class validParentheses(object):
    """
    LIFO (Last-In, First-Out): Stack
    - Time Complexity: O(N)
    - Space Complexity: O(N)
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
    LIFO (Last-In, First-Out): Stack
    - Time Complexity: O(N)
    - Space Complexity: O(N)
    """
    def solution(self, s: str) -> bool:
        stack = []

        mapping = {")": "(", "}": "{", "]": "["}

        for char in s:
            if char in mapping.values():
                stack.append(char)
            elif char in mapping.keys():
                if not stack or mapping[char] != stack.pop():
                    return False
            else:
                return False

        return not stack
