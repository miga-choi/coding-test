#include <stdbool.h>
#include <stdlib.h>

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
*/

/**
 * Complexities:
 *   - Time Complexity:
 *     push(x): O(1)
 *     pop(): O(1)
 *     peek(): O(1)
 *     empty(): O(1)
 *   - Space Complexity: O(N)
 */
typedef struct {
    int* input;
    int* output;
    int inputIndex;
    int outputIndex;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* myQueue = (MyQueue*)malloc(1 * sizeof(MyQueue));

    myQueue->input = (int*)malloc(100 * sizeof(int));
    myQueue->output = (int*)malloc(100 * sizeof(int));
    myQueue->inputIndex = -1;
    myQueue->outputIndex = -1;

    return myQueue;
}

// Pushes element x to the back of the queue.
void myQueuePush(MyQueue* obj, int x) {
    obj->inputIndex++;
    obj->input[obj->inputIndex] = x;
}

// Removes the element from the front of the queue and returns it.
int myQueuePop(MyQueue* obj) {
    int front = myQueuePeek(obj);

    if (front != -1) {
        obj->outputIndex--;
    }

    return front;
}

// Returns the element at the front of the queue.
int myQueuePeek(MyQueue* obj) {
    if (obj->outputIndex < 0) {
        while (obj->inputIndex >= 0) {
            obj->outputIndex++;
            obj->output[obj->outputIndex] = obj->input[obj->inputIndex];
            obj->inputIndex--;
        }
    }

    return obj->outputIndex < 0 ? -1 : obj->output[obj->outputIndex];
}

// Returns true if the queue is empty, false otherwise.
bool myQueueEmpty(MyQueue* obj) {
    return obj->inputIndex == -1 && obj->outputIndex == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->input);
    free(obj->output);
    free(obj);
}


// Solution
/**
 * Complexities:
 *   - Time Complexity:
 *     push(x): O(1)
 *     pop(): O(1)
 *     peek(): O(1)
 *     empty(): O(1)
 *   - Space Complexity: O(N)
 */
typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(capacity * sizeof(int));
    s->top = -1;
    s->capacity = capacity;
    return s;
}

void push(Stack* s, int val) {
    s->data[++(s->top)] = val;
}

int pop(Stack* s) {
    return s->data[(s->top)--];
}

int peek(Stack* s) {
    return s->data[s->top];
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void freeStack(Stack* s) {
    free(s->data);
    free(s);
}

typedef struct {
    Stack* s1;
    Stack* s2;
} SolutionMyQueue;

SolutionMyQueue* solutionMyQueueCreate() {
    SolutionMyQueue* obj = (SolutionMyQueue*)malloc(sizeof(SolutionMyQueue));
    obj->s1 = createStack(200);
    obj->s2 = createStack(200);
    return obj;
}

void solutionMyQueuePush(SolutionMyQueue* obj, int x) {
    push(obj->s1, x);
}

int solutionMyQueuePop(SolutionMyQueue* obj) {
    if (isEmpty(obj->s2)) {
        while (!isEmpty(obj->s1)) {
            push(obj->s2, pop(obj->s1));
        }
    }
    return pop(obj->s2);
}

int solutionMyQueuePeek(SolutionMyQueue* obj) {
    if (isEmpty(obj->s2)) {
        while (!isEmpty(obj->s1)) {
            push(obj->s2, pop(obj->s1));
        }
    }
    return peek(obj->s2);
}

bool solutionMyQueueEmpty(SolutionMyQueue* obj) {
    return isEmpty(obj->s1) && isEmpty(obj->s2);
}

void solutionMyQueueFree(SolutionMyQueue* obj) {
    freeStack(obj->s1);
    freeStack(obj->s2);
    free(obj);
}
