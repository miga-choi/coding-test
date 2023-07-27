class MyQueue:
    def __init__(self):
        self.inputStack = []
        self.outputStack = []

    def push(self, x: int) -> None:
        self.inputStack.append(x)

    def pop(self) -> int:
        if len(self.outputStack) == 0:
            while len(self.inputStack) > 0:
                self.outputStack.append(self.inputStack.pop())
        return self.outputStack.pop()

    def peek(self) -> int:
        if len(self.outputStack) > 0:
            return self.outputStack[len(self.outputStack) - 1]
        return self.inputStack[0]

    def empty(self) -> bool:
        return len(self.inputStack) == 0 and len(self.outputStack) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()


# Best Solution
class BestSolution(object):
    def __init__(self):
        self.in_stk = []
        self.out_stk = []

    # Push element x to the back of queue...
    def push(self, x):
        self.in_stk.append(x)

    # Remove the element from the front of the queue and returns it...
    def pop(self):
        self.peek()
        return self.out_stk.pop()

    # Get the front element...
    def peek(self):
        if not self.out_stk:
            while self.in_stk:
                self.out_stk.append(self.in_stk.pop())
        return self.out_stk[-1]

    # Return whether the queue is empty...
    def empty(self):
        return not self.in_stk and not self.out_stk
