import java.util.Stack;

class ImplementQueueUsingStacks {
    private Stack<Integer> inputStack;
    private Stack<Integer> outputStack;
    private int front;

    public ImplementQueueUsingStacks() {
        inputStack = new Stack<Integer>();
        outputStack = new Stack<Integer>();
        front = 0;
    }

    public void push(int x) {
        if (inputStack.size() == 0) {
            front = x;
        }
        inputStack.add(x);
    }

    public int pop() {
        if (outputStack.size() == 0) {
            while (inputStack.size() > 0) {
                outputStack.add(inputStack.pop());
            }
        }
        return outputStack.pop();
    }

    public int peek() {
        if (outputStack.size() == 0) {
            return front;
        }
        return outputStack.peek();
    }

    public boolean empty() {
        return inputStack.size() == 0 && outputStack.size() == 0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */


// Best Solution
class ImplementQueueUsingStacks_BestSolution {
    Stack<Integer> input = new Stack<Integer>();
    Stack<Integer> output = new Stack<Integer>();

    public void push(int x) {
        input.push(x);
    }

    public void pop() {
        peek();
        output.pop();
    }

    public int peek() {
        if (output.empty())
            while (!input.empty())
                output.push(input.pop());
        return output.peek();
    }

    public boolean empty() {
        return input.empty() && output.empty();
    }
}