#include <queue>
using namespace std;

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
public:
    queue<int> myQueue;

    MyStack() {}

    // Pushes element x to the top of the stack.
    void push(int x) {
        myQueue.push(x);
        for (int i = 0; i < myQueue.size() - 1; i++) {
            int firstElement = myQueue.front();
            myQueue.push(firstElement);
            myQueue.pop();
        }
    }

    // Removes the element on the top of the stack and returns it.
    int pop() {
        int firstElement = myQueue.front();
        myQueue.pop();
        return firstElement;
    }

    // Returns the element on the top of the stack.
    int top() {
        return myQueue.front();
    }

    // Returns `true` if the stack is empty, `false` otherwise.
    bool empty() {
        return myQueue.empty();
    }
};


// Solution
class Solution {
    queue<int> que;
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
        for (int i = 0; i < que.size() - 1; ++i) {
            que.push(que.front());
            que.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        que.pop();
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};
