class validParentheses(object):
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

        return len(stack) <= 0


    # Best Solution
    def bestSolution(self, s: str) -> bool:
        # 1. if it's the left bracket then we append it to the stack
        # 2. else if it's the right bracket and the stack is empty(meaning no matching left bracket), or the left bracket doesn't match
        # 3. finally check if the stack still contains unmatched left bracket
        d = {"(": ")", "{": "}", "[": "]"}
        stack = []
        for i in s:
            print(stack)
            if i in d:  # 1
                stack.append(i)
            elif len(stack) == 0 or d[stack.pop()] != i:  # 2
                return False
        return len(stack) == 0  # 3
