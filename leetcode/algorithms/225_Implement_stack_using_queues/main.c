#include <stdbool.h>
#include <stdlib.h>

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
*/

// Solution
/**
 * Complexities:
 *   - Time Complexity:
 *     push: O(N)
 *     pop: O(1)
 *     top: O(1)
 *     empty: O(1)
 *   - Space Complexity: O(N)
 */
typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % q->capacity;
}

int dequeue(Queue* q) {
    int val = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return val;
}

int peek(Queue* q) {
    return q->data[q->front];
}

int size(Queue* q) {
    return (q->rear - q->front + q->capacity) % q->capacity;
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}

typedef struct {
    Queue* q;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->q = createQueue(200); 
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    int sz = size(obj->q);
    
    enqueue(obj->q, x);
    
    for (int i = 0; i < sz; i++) {
        enqueue(obj->q, dequeue(obj->q));
    }
}

int myStackPop(MyStack* obj) {
    return dequeue(obj->q);
}

int myStackTop(MyStack* obj) {
    return peek(obj->q);
}

bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->q);
}

void myStackFree(MyStack* obj) {
    freeQueue(obj->q);
    free(obj);
}
