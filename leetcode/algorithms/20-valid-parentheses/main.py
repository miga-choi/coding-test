class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        sMap = {'(': ')', '{': '}', '[': ']'}
        lastIndex = s.rfind('(')
        if s.rfind('[') > lastIndex:
            lastIndex = s.rfind('[')
        if s.rfind('{') > lastIndex:
            lastIndex = s.rfind('{')
        print(lastIndex)
        return null

    # best solution
    def bestSolution(self, s):
        # 1. if it's the left bracket then we append it to the stack
        # 2. else if it's the right bracket and the stack is empty(meaning no matching left bracket), or the left bracket doesn't match
        # 3. finally check if the stack still contains unmatched left bracket
        d = {'(': ')', '{': '}', '[': ']'}
        stack = []
        for i in s:
            print(stack)
            if i in d:  # 1
                stack.append(i)
            elif len(stack) == 0 or d[stack.pop()] != i:  # 2
                return False
        return len(stack) == 0  # 3
