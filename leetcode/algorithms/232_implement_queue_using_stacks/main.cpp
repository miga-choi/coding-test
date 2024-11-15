#include <stack>
using namespace std;

class MyQueue
{
    stack<int> input, output;

public:
    MyQueue()
    {
    }

    // Pushes element x to the back of the queue.
    void push(int x)
    {
        input.push(x);
    }

    // Removes the element from the front of the queue and returns it.
    int pop()
    {
        int front = peek();
        output.pop();
        return front;
    }

    // Returns the element at the front of the queue.
    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    // Returns true if the queue is empty, false otherwise.
    bool empty()
    {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// Best Solution
class BestSolution
{
    stack<int> input, output;

public:
    void push(int x)
    {
        input.push(x);
    }

    void pop(void)
    {
        peek();
        output.pop();
    }

    int peek(void)
    {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool empty(void)
    {
        return input.empty() && output.empty();
    }
};
