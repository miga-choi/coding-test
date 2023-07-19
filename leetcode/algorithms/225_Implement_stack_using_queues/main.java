import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class MyStack {
    Stack<Integer> inputStack;
    Stack<Integer> outputStack;

    public MyStack() {
        inputStack = new Stack<Integer>();
        outputStack = new Stack<Integer>();

    }

    public void push(int x) {
        if (inputStack.size() > 0) {
            outputStack.push(inputStack.pop());
        }
        inputStack.push(x);
    }

    public int pop() {
        if (inputStack.size() > 0) {
            return inputStack.pop();
        }
        return outputStack.pop();
    }

    public int top() {
        if (inputStack.size() > 0) {
            return inputStack.firstElement();
        }
        return outputStack.lastElement();
    }

    public boolean empty() {
        if (inputStack.size() > 0 || outputStack.size() > 0) {
            return false;
        }
        return true;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */


// Best Solution
class BestSolution {

    private Queue<Integer> queue = new LinkedList<>();

    public void push(int x) {
        queue.add(x);
        for (int i = 1; i < queue.size(); i++)
            queue.add(queue.remove());
    }

    public void pop() {
        queue.remove();
    }

    public int top() {
        return queue.peek();
    }

    public boolean empty() {
        return queue.isEmpty();
    }
}